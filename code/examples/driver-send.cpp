void CAN::Driver::send(const CAN::Frame &message) {
    using namespace CAN;

    memset(&Driver::txFifo, 0, MCAN1_TX_FIFO_BUFFER_ELEMENT_SIZE);

    Driver::txFifo.brs = 1;
    Driver::txFifo.fdf = 1;
    Driver::txFifo.xtd = 0;
    Driver::txFifo.id = Driver::writeId(message.id);
    Driver::txFifo.dlc = Driver::convertLengthToDLC(message.data.size());

    std::copy(message.data.begin(), message.data.end(), Driver::txFifo.data);

    if (AcubeSATParameters::obcCANBUSActive.getValue() == Main) {
        MCAN0_MessageTransmitFifo(1, &Driver::txFifo);
    } else {
        MCAN1_MessageTransmitFifo(1, &Driver::txFifo);
    }
}
