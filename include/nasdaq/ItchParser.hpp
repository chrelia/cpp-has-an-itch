#pragma once

#include "nasdaq/ItchTypes.hpp"
#include <cstddef>

namespace CppHasAnItch {

    namespace ITCH {
        
        class ItchParser {
            
            public:
                ItchParser() = default;

                inline void parse(const char* buffer, size_t size);

                template <class Message>
                inline Message parseMessage(const char* buffer, size_t size, size_t offset = 0);
            
            private:
                template <class Message>
                inline void handleMessage(Message &m);

                inline SystemEventMessage parseSystemEventMessage(char* buffer, size_t size);
                inline StockDirectoryMessage parseStockDirectoryMessage(char* buffer, size_t size);
                inline StockTradingActionMessage parseStockTradingAction(char* buffer, size_t size);
                inline RegSHORestrictionMessage parseRegSHORestrictionMessage(char* buffer, size_t size);
                inline MarketParticipantPositionMessage parseMarketParticipantPositionMessage(char* buffer, size_t size);
                inline MWCBDeclineLevelMessage parseMWCBDeclineLevelMessage(char* buffer, size_t size);
                inline MWCBStatusMessage parseMWCBStatusMessage(char* buffer, size_t size);
                inline QuotingPeriodUpdateMessage parseQuotingPeriodUpdateMessage(char* buffer, size_t size);
                inline LULDAuctionCollarMessage parseLULDAuctionCollarMessage(char* buffer, size_t size);
                inline OperationHaltMessage parseOperationHaltMessage(char* buffer, size_t size);
                inline AddOrderMessage parseAddOrderMessage(char* buffer, size_t size);
                inline AddOrderWithMPIDMessage parseAddOrderWithMPIDMessage(char* buffer, size_t size);
                inline OrderExecutedMessage parseOrderExecutedMessage(char* buffer, size_t size);
                inline OrderExecutedWithPriceMessage parseOrderExecutedWithPriceMessage(char* buffer, size_t size);
                inline OrderCancelMessage parseOrderCancelMessage(char* buffer, size_t size);
                inline OrderDeleteMessage parseOrderDeleteMessage(char* buffer, size_t size);
                inline OrderReplaceMessage parseOrderReplaceMessage(char* buffer, size_t size);
                inline TradeNonCrossMessage parseTradeNonCrossMessage(char* buffer, size_t size);
                inline TradeCrossMessage parseTradeCrossMessage(char* buffer, size_t size);
                inline BrokenTradeMessage parseBrokenTradeMessage(char* buffer, size_t size);
                inline NOIIMessage parseNOIIMessage(char* buffer, size_t size);
                inline RPIIMessage parseRPIIMessage(char* buffer, size_t size);
                inline DLCRPDMessage parseDLCRPDMessage(char* buffer, size_t size);

        };
    }
}