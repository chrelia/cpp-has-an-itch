#include "nasdaq/ItchParser.hpp"
#include "nasdaq/ItchTypes.hpp"
#include "utils/macros.hpp"
#include <cstring>

namespace CppHasAnItch {


    namespace ITCH {

        void parse(const char* buffer, size_t size) {

            size_t index = 0;

            while (index < size) {

                size_t offset = 0;

                auto type = buffer[offset];

                switch (type) {

                    case static_cast<char>(MessageType::SystemEventMessage): {

                    }
                }





            }
        }



        
        template<SystemEventMessage>
        inline SystemEventMessage parseMessage(const char* buffer, size_t size, size_t offset = 0) {
            ASSERT((sizeof(SystemEventMessage) > size - offset), "SystemEventMessage > size - offset")

            SystemEventMessage m;
            mempcpy(&m, buffer + offset, sizeof(SystemEventMessage));

            // normalize
            // m.StockLocate;
            // m.TrackingNumber
            // m.Timestamp

            return m;
        }


        template<StockDirectoryMessage>
        inline StockDirectoryMessage parseMessage(const char* buffer, size_t size, size_t offset = 0) {
            ASSERT((sizeof(StockDirectoryMessage) > size - offset), "StockDirectoryMessage > size - offset")

            StockDirectoryMessage m;
            mempcpy(&m, buffer + offset, sizeof(StockDirectoryMessage));

            // normalize
            // m.StockLocate
            // m.TrackingNumber
            // m.Timestamp
            // m.RoundLotSize
            // m.ETPLeverageFactor

            return m;
        }

        template<StockTradingActionMessage>
        inline StockTradingActionMessage parseMessage(const char* buffer, size_t size, size_t offset = 0) {
            ASSERT((sizeof(StockTradingActionMessage) > size - offset), "StockTradingActionMessage > size - offset");

            StockTradingActionMessage m;
            memcpy(&m, buffer + offset, sizeof(StockTradingActionMessage));
            
            // normalize
            // m.StockLocate;
            // m.TrackingNumber
            // m.Timestamp;

            return m;
        }
        
    }

    
   
};