#include "nasdaq/ItchParser.hpp"
#include "nasdaq/ItchTypes.hpp"
#include "utils/macros.hpp"
#include <cstring>

namespace CppHasAnItch {

    namespace ITCH {
        
        void ItchParser::parse(const char* buffer, size_t size) {

            size_t index = 0;

            while (index < size) {

                size_t offset = 0;

                auto type = buffer[offset];

                switch (type) {

                    case static_cast<char>(MessageType::SystemEventMessage): {
                        SystemEventMessage m;
                        parseMessage(m, buffer, size, offset);
                    }
                }





            }
        }



        
       


        // template<StockDirectoryMessage>
        // inline StockDirectoryMessage normalizeMessage(const char* buffer, size_t size, size_t offset = 0) {
        //     ASSERT((sizeof(StockDirectoryMessage) > size - offset), "StockDirectoryMessage > size - offset")

        //     StockDirectoryMessage m;
        //     mempcpy(&m, buffer + offset, sizeof(StockDirectoryMessage));

        //     // normalize
        //     // m.StockLocate
        //     // m.TrackingNumber
        //     // m.Timestamp
        //     // m.RoundLotSize
        //     // m.ETPLeverageFactor

        //     return m;
        // }

        template<StockTradingActionMessage>
        inline StockTradingActionMessage normalizeMessage(StockTradingActionMessage& m, const char* buffer, size_t size, size_t offset = 0) {
                 
            // normalize
            // m.StockLocate;
            // m.TrackingNumber
            // m.Timestamp;

            return m;
        }

        template<RegSHORestrictionMessage>
        inline RegSHORestrictionMessage normalizeMessage(const char* buffer, size_t size, size_t offset = 0) {
            ASSERT((sizeof(RegSHORestrictionMessage) > size - offset), "RegSHORestrictionMessage > size - offset");

            RegSHORestrictionMessage m;
            memcpy(&m, buffer + offset, sizeof(RegSHORestrictionMessage));


            // normalize
            // LocateCode
            // TrackingNumber
            // Timestamp

            return m;
        }

        template<MarketParticipantPositionMessage>
        inline MarketParticipantPositionMessage normalizeMessage(const char* buffer, size_t size, size_t offset = 0) {
            ASSERT((sizeof(MarketParticipantPositionMessage) > size - offset), "MarketParticipantPositionMessage > size - offset");

            MarketParticipantPositionMessage m;
            memcpy(&m, buffer + offset, sizeof(MarketParticipantPositionMessage));


            // normalize
            // StockLocate
            // TrackingNumber
            // Timestamp

            return m;
        }

        template<MWCBDeclineLevelMessage>
        inline MWCBDeclineLevelMessage normalizeMessage(const char* buffer, size_t size, size_t offset = 0) {
            ASSERT((sizeof(MWCBDeclineLevelMessage) > size - offset), "MWCBDeclineLevelMessage > size - offset");

            MWCBDeclineLevelMessage m;
            memcpy(&m, buffer + offset, sizeof(MWCBDeclineLevelMessage));


            // normalize
            // StockLocate
            // TrackingNumber
            // Timestamp
            // Level1
            // Level2
            // Level3

            return m;
        }

        template<MWCBStatusMessage>
        inline MWCBStatusMessage normalizeMessage(const char* buffer, size_t size, size_t offset = 0) {
            ASSERT((sizeof(MWCBStatusMessage) > size - offset), "MWCBStatusMessage > size - offset");

            MWCBStatusMessage m;
            memcpy(&m, buffer + offset, sizeof(MWCBStatusMessage));


            // normalize
            // StockLocate
            // TrackingNumber
            // Timestamp

            return m;
        }

        template<QuotingPeriodUpdateMessage>
        inline QuotingPeriodUpdateMessage normalizeMessage(const char* buffer, size_t size, size_t offset = 0) {
            ASSERT((sizeof(QuotingPeriodUpdateMessage) > size - offset), "QuotingPeriodUpdateMessage > size - offset");

            QuotingPeriodUpdateMessage m;
            memcpy(&m, buffer + offset, sizeof(QuotingPeriodUpdateMessage));


            // normalize
            // StockLocate
            // TrackingNumber
            // Timestamp
            // IPOQuotationReleaseTime
            // IPOPrice

            return m;
        }

        template<LULDAuctionCollarMessage>
        inline LULDAuctionCollarMessage normalizeMessage(const char* buffer, size_t size, size_t offset = 0) {
            ASSERT((sizeof(LULDAuctionCollarMessage) > size - offset), "LULDAuctionCollarMessage > size - offset");

            LULDAuctionCollarMessage m;
            memcpy(&m, buffer + offset, sizeof(LULDAuctionCollarMessage));


            // normalize
            // StockLocate
            // TrackingNumber
            // Timestamp
            // AuctionCollarReferencePrice
            // UpperAuctionCollarPrice
            // LowerAuctionCollarPrice
            // AuctionCollarExtension

            return m;
        }

        template<OperationHaltMessage>
        inline OperationHaltMessage normalizeMessage(const char* buffer, size_t size, size_t offset = 0) {
            ASSERT((sizeof(OperationHaltMessage) > size - offset), "OperationHaltMessage > size - offset");

            OperationHaltMessage m;
            memcpy(&m, buffer + offset, sizeof(OperationHaltMessage));


            // normalize
            // StockLocate
            // TrackingNumber
            // Timestamp

            return m;
        }

        template<AddOrderMessage>
        inline AddOrderMessage normalizeMessage(const char* buffer, size_t size, size_t offset = 0) {
            ASSERT((sizeof(AddOrderMessage) > size - offset), "AddOrderMessage > size - offset");

            AddOrderMessage m;
            memcpy(&m, buffer + offset, sizeof(AddOrderMessage));


            // normalize
            // StockLocate
            // TrackingNumber
            // Timestamp
            // OrderReferenceNumber
            // Price

            return m;
        }

        template<AddOrderWithMPIDMessage>
        inline AddOrderWithMPIDMessage normalizeMessage(const char* buffer, size_t size, size_t offset = 0) {
            ASSERT((sizeof(AddOrderWithMPIDMessage) > size - offset), "AddOrderWithMPIDMessage > size - offset");

            AddOrderWithMPIDMessage m;
            memcpy(&m, buffer + offset, sizeof(AddOrderWithMPIDMessage));


            // normalize
            // StockLocate
            // TrackingNumber
            // Timestamp
            // OrderReferenceNumber
            // Price

            return m;
        }

        template<OrderExecutedMessage>
        inline OrderExecutedMessage normalizeMessage(const char* buffer, size_t size, size_t offset = 0) {
            ASSERT((sizeof(OrderExecutedMessage) > size - offset), "OrderExecutedMessage > size - offset");

            OrderExecutedMessage m;
            memcpy(&m, buffer + offset, sizeof(OrderExecutedMessage));


            // normalize
            // StockLocate
            // TrackingNumber
            // Timestamp
            // OrderReferenceNumber
            // ExecutedShares
            // MatchNumber

            return m;
        }

        template<OrderExecutedWithPriceMessage>
        inline OrderExecutedWithPriceMessage normalizeMessage(const char* buffer, size_t size, size_t offset = 0) {
            ASSERT((sizeof(OrderExecutedWithPriceMessage) > size - offset), "OrderExecutedWithPriceMessage > size - offset");

            OrderExecutedWithPriceMessage m;
            memcpy(&m, buffer + offset, sizeof(OrderExecutedWithPriceMessage));


            // normalize
            // StockLocate
            // TrackingNumber
            // Timestamp
            // OrderReferenceNumber
            // ExecutedShares
            // MatchNumber
            // ExecutionPrice

            return m;
        }

        template<OrderCancelMessage>
        inline OrderCancelMessage normalizeMessage(const char* buffer, size_t size, size_t offset = 0) {
            ASSERT((sizeof(OrderCancelMessage) > size - offset), "OrderExecutedWithPriceMessage > size - offset");

            OrderCancelMessage m;
            memcpy(&m, buffer + offset, sizeof(OrderCancelMessage));


            // normalize
            // StockLocate
            // TrackingNumber
            // Timestamp
            // OrderReferenceNumber
            // CancelledShares

            return m;
        }

        template<OrderDeleteMessage>
        inline OrderDeleteMessage normalizeMessage(const char* buffer, size_t size, size_t offset = 0) {
            ASSERT((sizeof(OrderDeleteMessage) > size - offset), "OrderDeleteMessage > size - offset");

            OrderDeleteMessage m;
            memcpy(&m, buffer + offset, sizeof(OrderDeleteMessage));


            // normalize
            // StockLocate
            // TrackingNumber
            // Timestamp
            // OrderReferenceNumber

            return m;
        }

        template<OrderReplaceMessage>
        inline OrderReplaceMessage normalizeMessage(const char* buffer, size_t size, size_t offset = 0) {
            ASSERT((sizeof(OrderReplaceMessage) > size - offset), "OrderReplaceMessage > size - offset");

            OrderReplaceMessage m;
            memcpy(&m, buffer + offset, sizeof(OrderReplaceMessage));


            // normalize
            // StockLocate
            // TrackingNumber
            // Timestamp
            // OriginalOrderReferenceNumber
            // NewOrderReferenceNumber
            // Shares
            // Price

            return m;
        }

        template<TradeNonCrossMessage>
        inline TradeNonCrossMessage normalizeMessage(const char* buffer, size_t size, size_t offset = 0) {
            ASSERT((sizeof(TradeNonCrossMessage) > size - offset), "TradeNonCrossMessage > size - offset");

            TradeNonCrossMessage m;
            memcpy(&m, buffer + offset, sizeof(TradeNonCrossMessage));


            // normalize
            // StockLocate
            // TrackingNumber
            // Timestamp
            // OrderReferenceNumber
            // Shares
            // Price
            // MatchNumber

            return m;
        }

        template<TradeCrossMessage>
        inline TradeCrossMessage normalizeMessage(const char* buffer, size_t size, size_t offset = 0) {
            ASSERT((sizeof(TradeCrossMessage) > size - offset), "TradeCrossMessage > size - offset");

            TradeCrossMessage m;
            memcpy(&m, buffer + offset, sizeof(TradeCrossMessage));


            // normalize
            // StockLocate
            // TrackingNumber
            // Timestamp
            // Shares
            // CrossPrice
            // MatchNumber

            return m;
        }

        template<BrokenTradeMessage>
        inline BrokenTradeMessage normalizeMessage(const char* buffer, size_t size, size_t offset = 0) {
            ASSERT((sizeof(BrokenTradeMessage) > size - offset), "BrokenTradeMessage > size - offset");

            BrokenTradeMessage m;
            memcpy(&m, buffer + offset, sizeof(BrokenTradeMessage));


            // normalize
            // StockLocate
            // TrackingNumber
            // Timestamp
            // MatchNumber

            return m;
        }

        template<NOIIMessage>
        inline NOIIMessage normalizeMessage(const char* buffer, size_t size, size_t offset = 0) {
            ASSERT((sizeof(NOIIMessage) > size - offset), "NOIIMessage > size - offset");

            NOIIMessage m;
            memcpy(&m, buffer + offset, sizeof(NOIIMessage));


            // normalize
            // StockLocate
            // TrackingNumber
            // Timestamp
            // PairedShares
            // ImbalanceShares
            // FarPrice
            // NearPrice
            // CurrentReferencePrice

            return m;
        }

        template<RPIIMessage>
        inline RPIIMessage normalizeMessage(const char* buffer, size_t size, size_t offset = 0) {
            ASSERT((sizeof(RPIIMessage) > size - offset), "RPIIMessage > size - offset");

            RPIIMessage m;
            memcpy(&m, buffer + offset, sizeof(RPIIMessage));


            // normalize
            // StockLocate
            // TrackingNumber
            // Timestamp

            return m;
        }

        template<DLCRPDMessage>
        inline DLCRPDMessage normalizeMessage(const char* buffer, size_t size, size_t offset = 0) {
            ASSERT((sizeof(DLCRPDMessage) > size - offset), "DLCRPDMessage > size - offset");

            DLCRPDMessage m;
            memcpy(&m, buffer + offset, sizeof(DLCRPDMessage));


            // normalize
            // StockLocate
            // TrackingNumber
            // Timestamp
            // MinimumAllowablePrice
            // MaximumAllowablePrice
            // NearExecutionPrice
            // LowerPriceCollar
            // UpperPriceCollar

            return m;
        }


        
    }

    
   
};