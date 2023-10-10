namespace CAN {
    /**
     * CAN Nodes, as specified in DDJF_OBDH.
     */
    enum NodeIDs : uint8_t {
        OBC = 0x0, COMMS = 0x1, ADCS = 0x2, SU = 0x3, ExternalMCU = 0x4
    };

    /**
     * The ID for the current node as described in DDJF_OBDH
     */
    inline const CAN::NodeIDs NodeID = OBC;

    /**
     * The maximum of the length of the queue for incoming/outgoing CAN frames.
     */
    inline const uint8_t FrameQueueSize = 20;

    /**
     * The maximum size for the data field of a CAN-TP message.
     */
    inline const uint16_t TPMessageMaximumSize = 256;

    /**
     * The maximum numbers of parameters, function arguments etc. inside a single CAN-TP Message.
     */
    inline const uint8_t TPMessageMaximumArguments = 10;

    /**
     * CAN_SILENT pins for each CAN transceiver.
     */
    inline const PIO_PIN CAN_SILENT_1 = PIO_PIN_NONE;

    inline const PIO_PIN CAN_SILENT_2 = PIO_PIN_NONE;
}
