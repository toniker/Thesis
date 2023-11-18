(gdb) break CANTestTask.cpp:43
Breakpoint 1 at 0x44b342: file /home/antonis/firmware/lib/cross-platform-software/src/FreeRTOSTasks/CANTestTask.cpp, line 43.
Note: automatically using hardware breakpoints for read-only addresses.
(gdb) c
Continuing.

Breakpoint 1, CANTestTask::execute (this=0x20421f8c <canTestTask>)
    at /home/antonis/firmware/lib/cross-platform-software/src/FreeRTOSTasks/CANTestTask.cpp:43
43              vTaskDelay(pdMS_TO_TICKS(1000));
(gdb) freertos task
CPU      - Processing on CPU number
ID       - TCB_t task memory address
PRI      - Task priority
B_PRI    - Base priority.
SS       - Used stack size.
SL       - Free/unused stack size.

 CPU                                   ID            NAME    STATUS PRI B_PRI MUTEXES_HELD   SS    SL 
---- ------------------------------------ --------------- --------- --- ----- ------------ ---- -----
          0x20415450 <xIdleTaskTCBBuffer>            IDLE     ready   0     0            0  100   292 
           0x20420acc <canGatekeeperTask> CANGatekeeperTa     ready   2     2            0  228  4964 
CPU0             0x20421f8c <canTestTask>        CAN Test     ready   4     4            0 1308  7884 
            0x20401a10 <housekeepingTask>    Housekeeping     ready   4     4            0 5292  2704 
          0x2040d238 <initializationTask> InitializationT suspended   4     4            0  124 33072 
     0x204039b8 <timeBasedSchedulingTask> TimeBasedSchedu suspended   2     2            0  188  9808 
      0x20418720 <ambientTemperatureTask> ExternalTempera suspended   2     2            0 1196  6796 
              0x20406a30 <tcHandlingTask>      TCHandling suspended   1     1            0 1828 22168 
          0x2041a6d8 <uartGatekeeperTask> UARTGatekeeperT suspended   2     2            0 1236  6760 
             0x2041576c <timeKeepingTask>     Timekeeping delayed_1   1     1            0  124  7868 
     0x20406130 <statisticsReportingTask> StatisticsRepor delayed_1   1     1            0  156  2040 
                0x2041fac4 <watchdogTask>        Watchdog delayed_1   0     0            0  660  3332 
          0x20417718 <mcuTemperatureTask> MCUTemperatureS delayed_1   2     2            0  812  3184 