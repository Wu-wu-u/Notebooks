# 虚拟化

## 程序和进程

> 操作系统通过进程抽象为应用程序提供了独立的执行环境。进程是操作系统中最基本的资源分配单位，它包含程序本身的状态和操作系统内部的状态。操作系统提供了一系列系统调用 (如 Linux 中的 fork、exec、wait 和 exit，Windows 中的 CreateProcess 和TerminateProcess) 来创建、管理和终止进程。

### 如何获取进程的基本信息


??? tip "使用API来获取进程信息"
    ```c
    #include <unistd.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <fcntl.h>
    #include <sys/resource.h>

    int main() {
        pid_t pid = getpid();
        printf("pid: %d\n", pid);

        pid_t ppid = getppid();
        printf("ppid: %d\n", ppid);
        printf("\n--- Additional Process Information ---\n");
        
        // Get the user ID and group ID
        uid_t uid = getuid();
        gid_t gid = getgid();
        printf("User ID: %d\n", uid);
        printf("Group ID: %d\n", gid);
        
        // Get the effective user ID and group ID
        uid_t euid = geteuid();
        gid_t egid = getegid();
        printf("Effective User ID: %d\n", euid);
        printf("Effective Group ID: %d\n", egid);
        
        // Get the number of open file descriptors
        int num_fds = sysconf(_SC_OPEN_MAX);
        printf("Max open file descriptors: %d\n", num_fds);
        
        // Get the process priority
        int priority = getpriority(PRIO_PROCESS, 0);
        printf("Process priority: %d\n", priority);

        // Display process status from /proc/self/status
        FILE *status_file = fopen("/proc/self/status", "r");
        if (status_file) {
            char line[256];
            printf("\n--- Process Status (/proc/self/status) ---\n");
            while (fgets(line, sizeof(line), status_file)) {
                // Print interesting fields like name, state, memory usage
                if (strncmp(line, "Name:", 5) == 0 ||
                    strncmp(line, "State:", 6) == 0 ||
                    strncmp(line, "PPid:", 5) == 0 ||
                    strncmp(line, "Uid:", 4) == 0 ||
                    strncmp(line, "VmSize:", 7) == 0) {
                    printf("%s", line);
                }
            }
            fclose(status_file);
        }
        
        // Display command line
        printf("\n--- Command Line (/proc/self/cmdline) ---\n");
        int cmdline_fd = open("/proc/self/cmdline", O_RDONLY);
        if (cmdline_fd >= 0) {
            char buffer[256];
            ssize_t bytes_read = read(cmdline_fd, buffer, sizeof(buffer) - 1);
            if (bytes_read > 0) {
                buffer[bytes_read] = '\0';
                // Replace null bytes with spaces for display
                for (int i = 0; i < bytes_read - 1; i++) {
                    if (buffer[i] == '\0') buffer[i] = ' ';
                }
                printf("Command line: %s\n", buffer);
            }
            close(cmdline_fd);
        }
        
        // Display current working directory
        printf("\n--- Current Directory (/proc/self/cwd) ---\n");
        char cwd[256] = {0};
        if (readlink("/proc/self/cwd", cwd, sizeof(cwd) - 1) != -1) {
            cwd[sizeof(cwd) - 1] = '\0';
            printf("Current directory: %s\n", cwd);
        }
        
        return 0;
    }
    ```

- 除了使用系统调用API，*Linux* `/proc`文件系统还允许我们使用文件API（*everything is a file*）来访问当前进程的ID、状态信息、命令行参数和工作目录等元数据

??? tip "`cat /proc/1/status`"
    ```bash
    Name:   sshd
    Umask:  0022
    State:  S (sleeping)
    Tgid:   1
    Ngid:   0
    Pid:    1
    PPid:   0
    TracerPid:      0
    Uid:    0       0       0       0
    Gid:    0       0       0       0
    FDSize: 64
    Groups:  
    NStgid: 1
    NSpid:  1
    NSpgid: 1
    NSsid:  1
    Kthread:        0
    VmPeak:   303108 kB
    VmSize:   301060 kB
    VmLck:         0 kB
    VmPin:         0 kB
    VmHWM:     15164 kB
    VmRSS:     15164 kB
    RssAnon:            6928 kB
    RssFile:            8236 kB
    RssShmem:              0 kB
    VmData:   286340 kB
    VmStk:       132 kB
    VmExe:       376 kB
    VmLib:      8944 kB
    VmPTE:       128 kB
    VmSwap:        0 kB
    HugetlbPages:          0 kB
    CoreDumping:    0
    THP_enabled:    1
    untag_mask:     0xffffffffffffff
    Threads:        1
    SigQ:   0/31325
    SigPnd: 0000000000000000
    ShdPnd: 0000000000000000
    SigBlk: 0000000000000000
    SigIgn: 0000000000001000
    SigCgt: 0000000000014415
    CapInh: 0000000000000000
    CapPrm: 00000000a80425fb
    CapEff: 00000000a80425fb
    CapBnd: 00000000a80425fb
    CapAmb: 0000000000000000
    NoNewPrivs:     0
    Seccomp:        0
    Seccomp_filters:        0
    Speculation_Store_Bypass:       thread vulnerable
    SpeculationIndirectBranch:      unknown
    Cpus_allowed:   ff
    Cpus_allowed_list:      0-7
    Mems_allowed:   1
    Mems_allowed_list:      0
    voluntary_ctxt_switches:        104
    nonvoluntary_ctxt_switches:     40
    ```

??? note "进程的pid是递增的？" 

    > Prompt: 我发现随着进程的创建，进程的 pid 是递增的；而 pid 是有限的 (32-bit 整数)，这是否意味着会循环导致 pid 重用？

    是的，您的观察是正确的。进程 ID (PID) 确实是有限的资源，通常是 32 位整数，理论上最大值为 2^32-1（约42亿）。随着进程不断创建，PID 会递增，当达到系统设定的最大值后，系统会循环并重新分配较小的、已经释放的 PID。

    关于 PID 重用的几个重要点：

    1. **PID 范围**：

    
    - 在大多数 Linux 系统中，PID 的默认范围是从 1 到 32767（*/proc/sys/kernel/pid_max*）
    
    - 在较新的 Linux 内核中，这个上限可以配置到 2^22（约400万）
    
    - 在 64 位系统上，理论上限可以更高
    
    2. **PID 分配机制**：

    
    - 系统会维护一个 PID 位图或类似的数据结构来跟踪已使用和可用的 PID
    
    - 新进程创建时，内核会分配下一个可用的 PID
    
    - 当 PID 达到最大值后，系统会从较小的值开始重新搜索可用的 PID
    
    3. **PID 重用策略**：

    - 系统不会立即重用刚刚释放的 PID，通常会有一个"冷却期"
    
    - 这是为了避免将新进程的 PID 分配给可能仍被其他进程引用的已终止进程
    
    4. **PID 重用的潜在问题**：

    - 安全隐患：如果一个进程正在引用另一个已终止的进程，而该 PID 被重用，可能导致权限问题
    
    - 竞态条件：在多线程或多进程环境中，PID 重用可能导致意外行为
    
    5. **PID 命名空间**：

    - 现代 Linux 内核支持 PID 命名空间，允许在容器或虚拟化环境中隔离 PID 空间
    
    - 这意味着不同命名空间中的进程可以使用相同的 PID 而不会冲突
    
    总结来说，是的，PID 确实会循环重用，这是操作系统设计的必然结果，因为 PID 是有限资源。操作系统通过各种机制（如延迟重用、PID 命名空间等）来减轻 PID 重用可能带来的问题。

### 进程（状态机）管理

- 理解 `fork()`: `fork()` 会完整复制状态机；新创建的状态机返回值为 **0**，执行 `fork()` 的进程会**返回子进程的进程号**。同时，操作系统中的进程是并行执行的。程序的精确行为并不显然——model checker 可以帮助我们理解它。

- 理解 `execve`: `execve` 有三个参数：*path*, *argv*, *envp*，分别是可执行文件的路径、传递给 main 函数的参数和环境变量。

