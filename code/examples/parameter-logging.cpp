for (uint16_t idx = 0; idx < parameterCount; idx++) {
    uint16_t parameterID = message.readUint16();
    if (Services.parameterManagement.parameterExists(parameterID)) {
        if constexpr (Logger::isLogged(Logger::debug)) {
            String<64> logString = "The value for parameter with ID ";
            etl::to_string(parameterID, logString, true);
            logString.append(" was ");

            auto parameter = Services.parameterManagement.getParameter(parameterID);
            etl::to_string(parameter->get().getValueAsDouble(), logString, true);

            parameter->get().setValueFromMessage(message);
            logString.append(" and is now ");
            etl::to_string(parameter->get().getValueAsDouble(), logString, true);

            LOG_DEBUG << logString.c_str();
        } else {
            Services.parameterManagement.getParameter(parameterID)->get().setValueFromMessage(message);
        }
    }
}