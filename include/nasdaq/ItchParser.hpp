#pragma once

#include "nasdaq/ItchTypes.hpp"
#include "nasdaq/ItchFormat.hpp"
#include "utils/Endian.hpp"
#include "utils/Macros.hpp"
#include <cstddef>
#include <cstring>

namespace CppHasAnItch {

    namespace ITCH {
        
        template <class Handler>
        class ItchParser {
            
            public:
                ItchParser() = delete;
                ItchParser(const ItchParser &parser) = delete;
                ItchParser(ItchParser &&parser) = delete;

                explicit ItchParser(Handler& handler): _handler(handler) {}

                inline void parse(const char* buffer, size_t size);

                inline size_t parseMessage(SystemEventMessage &m, const char* buffer, size_t size);
                inline size_t parseMessage(StockDirectoryMessage &m, const char* buffer, size_t size);
                inline size_t parseMessage(StockTradingActionMessage &m, const char* buffer, size_t size);
                inline size_t parseMessage(RegSHORestrictionMessage &m, const char* buffer, size_t size);
                inline size_t parseMessage(MarketParticipantPositionMessage &m, const char* buffer, size_t size);
                inline size_t parseMessage(MWCBDeclineLevelMessage &m, const char* buffer, size_t size);
                inline size_t parseMessage(MWCBStatusMessage &m, const char* buffer, size_t size);
                inline size_t parseMessage(LULDAuctionCollarMessage &m, const char* buffer, size_t size);
                inline size_t parseMessage(OperationHaltMessage &m, const char* buffer, size_t size);
                inline size_t parseMessage(AddOrderMessage &m, const char* buffer, size_t size);
                inline size_t parseMessage(AddOrderWithMPIDMessage &m, const char* buffer, size_t size);
                inline size_t parseMessage(OrderExecutedMessage &m, const char* buffer, size_t size);
                inline size_t parseMessage(OrderExecutedWithPriceMessage &m, const char* buffer, size_t size);
                inline size_t parseMessage(OrderCancelMessage &m, const char* buffer, size_t size);
                inline size_t parseMessage(OrderDeleteMessage &m, const char* buffer, size_t size);
                inline size_t parseMessage(OrderReplaceMessage &m, const char* buffer, size_t size);
                inline size_t parseMessage(TradeNonCrossMessage &m, const char* buffer, size_t size);
                inline size_t parseMessage(TradeCrossMessage &m, const char* buffer, size_t size);
                inline size_t parseMessage(BrokenTradeMessage &m, const char* buffer, size_t size);
                inline size_t parseMessage(NOIIMessage &m, const char* buffer, size_t size);
                inline size_t parseMessage(RPIIMessage &m, const char* buffer, size_t size);
                inline size_t parseMessage(DLCRPDMessage &m, const char* buffer, size_t size);

                
            private:
                Handler _handler;

        };

        template<class Handler>
        void ItchParser<Handler>::parse(const char* buffer, size_t size) {

            size_t index = 0;

            while (index < size) {

                auto type = buffer[index];

                switch (type) {

                    case SystemEventMessage::MessageType: {
                        SystemEventMessage m;
                        parseMessage(m, buffer, size);
                    }
                }





            }
        }
        
        inline size_t parseMessage(SystemEventMessage &m, const char* buffer, size_t size, size_t offset) {
            ASSERT((size - offset >= SystemEventMessage::WireSize), "SystemEventMessage buffer < WireSize");
            
            offset += sizeof(SystemEventMessage::MessageType);
            offset += CppHasAnItch::Utils::BigToNative(m.StockLocate, &buffer[offset]);
            offset += CppHasAnItch::Utils::BigToNative(m.TrackingNumber, &buffer[offset]);
            offset += CppHasAnItch::ITCH::ParseToTimestamp(m.Timestamp, &buffer[offset]);
            offset += CppHasAnItch::ITCH::ParseToString(&m.EventCode, &buffer[offset], sizeof(m.EventCode));

            return SystemEventMessage::WireSize;
        }

        inline size_t parseMessage(StockDirectoryMessage &m, const char* buffer, size_t size, size_t offset) {
            ASSERT((size - offset >= StockDirectoryMessage::WireSize), "SystemEventMessage buffer < WireSize");
            
            offset += sizeof(StockDirectoryMessage::MessageType);
            offset += CppHasAnItch::Utils::BigToNative(m.StockLocate, &buffer[offset]);
            offset += CppHasAnItch::Utils::BigToNative(m.TrackingNumber, &buffer[offset]);
            offset += CppHasAnItch::ITCH::ParseToTimestamp(m.Timestamp, &buffer[offset]);
            offset += CppHasAnItch::ITCH::ParseToString(&m.Stock[0], &buffer[offset], sizeof(m.Stock));
            offset += CppHasAnItch::ITCH::ParseToString(&m.MarketCategory, &buffer[offset], sizeof(m.MarketCategory));
            offset += CppHasAnItch::ITCH::ParseToString(&m.FinancialStatusIndicator, &buffer[offset], sizeof(m.FinancialStatusIndicator));
            offset += CppHasAnItch::Utils::BigToNative(m.RoundLotSize, &buffer[offset]);
            offset += CppHasAnItch::ITCH::ParseToString(&m.RoundLotsOnly, &buffer[offset], sizeof(m.RoundLotsOnly));
            offset += CppHasAnItch::ITCH::ParseToString(&m.IssueClassification, &buffer[offset], sizeof(m.IssueClassification));
            offset += CppHasAnItch::ITCH::ParseToString(&m.IssueSubType[0], &buffer[offset], sizeof(m.IssueSubType));
            offset += CppHasAnItch::ITCH::ParseToString(&m.Authenticity, &buffer[offset], sizeof(m.Authenticity));
            offset += CppHasAnItch::ITCH::ParseToString(&m.ShortSaleThresholdIndicator, &buffer[offset], sizeof(m.ShortSaleThresholdIndicator));
            offset += CppHasAnItch::ITCH::ParseToString(&m.IPOFlag, &buffer[offset], sizeof(m.IPOFlag));
            offset += CppHasAnItch::ITCH::ParseToString(&m.LULDReferencePriceTier, &buffer[offset], sizeof(m.LULDReferencePriceTier));
            offset += CppHasAnItch::ITCH::ParseToString(&m.ETPFlag, &buffer[offset], sizeof(m.ETPFlag));
            offset += CppHasAnItch::Utils::BigToNative(m.ETPLeverageFactor, &buffer[offset]);
            offset += CppHasAnItch::ITCH::ParseToString(&m.InverseIndicator, &buffer[offset], sizeof(m.InverseIndicator));

            return StockDirectoryMessage::WireSize;
        }

        inline size_t parseMessage(StockTradingActionMessage &m, const char* buffer, size_t size, size_t offset) {
            ASSERT((size - offset >= StockTradingActionMessage::WireSize), "SystemEventMessage buffer < WireSize");
            
            offset += sizeof(StockTradingActionMessage::MessageType);
            offset += CppHasAnItch::Utils::BigToNative(m.StockLocate, &buffer[offset]);
            offset += CppHasAnItch::Utils::BigToNative(m.TrackingNumber, &buffer[offset]);
            offset += CppHasAnItch::ITCH::ParseToTimestamp(m.Timestamp, &buffer[offset]);
            offset += CppHasAnItch::ITCH::ParseToString(&m.Stock[0], &buffer[offset], sizeof(m.Stock));
            offset += CppHasAnItch::ITCH::ParseToString(&m.TradingState, &buffer[offset], sizeof(m.TradingState));
            offset += CppHasAnItch::ITCH::ParseToString(&m.Reserved, &buffer[offset], sizeof(m.Reserved));
            offset += CppHasAnItch::ITCH::ParseToString(&m.Reason[0], &buffer[offset], sizeof(m.Reason));

            return StockTradingActionMessage::WireSize;
        }

        inline size_t parseMessage(RegSHORestrictionMessage &m, const char* buffer, size_t size, size_t offset) {
            ASSERT((size - offset >= RegSHORestrictionMessage::WireSize), "SystemEventMessage buffer < WireSize");
            
            offset += sizeof(RegSHORestrictionMessage::MessageType);
            offset += CppHasAnItch::Utils::BigToNative(m.LocateCode, &buffer[offset]);
            offset += CppHasAnItch::Utils::BigToNative(m.TrackingNumber, &buffer[offset]);
            offset += CppHasAnItch::ITCH::ParseToTimestamp(m.Timestamp, &buffer[offset]);
            offset += CppHasAnItch::ITCH::ParseToString(&m.Stock[0], &buffer[offset], sizeof(m.Stock));
            offset += CppHasAnItch::ITCH::ParseToString(&m.RegSHOAction, &buffer[offset], sizeof(m.RegSHOAction));

            return RegSHORestrictionMessage::WireSize;
        }

        inline size_t parseMessage(MarketParticipantPositionMessage &m, const char* buffer, size_t size, size_t offset) {
            ASSERT((size - offset >= MarketParticipantPositionMessage::WireSize), "SystemEventMessage buffer < WireSize");
            
            offset += sizeof(MarketParticipantPositionMessage::MessageType);
            offset += CppHasAnItch::Utils::BigToNative(m.StockLocate, &buffer[offset]);
            offset += CppHasAnItch::Utils::BigToNative(m.TrackingNumber, &buffer[offset]);
            offset += CppHasAnItch::ITCH::ParseToTimestamp(m.Timestamp, &buffer[offset]);
            offset += CppHasAnItch::ITCH::ParseToString(&m.MPID[0], &buffer[offset], sizeof(m.MPID));
            offset += CppHasAnItch::ITCH::ParseToString(&m.Stock[0], &buffer[offset], sizeof(m.Stock));
            offset += CppHasAnItch::ITCH::ParseToString(&m.PrimaryMarketMaker, &buffer[offset], sizeof(m.PrimaryMarketMaker));
            offset += CppHasAnItch::ITCH::ParseToString(&m.MarketMakerMode, &buffer[offset], sizeof(m.MarketMakerMode));
            offset += CppHasAnItch::ITCH::ParseToString(&m.MarketParticipantState, &buffer[offset], sizeof(m.MarketParticipantState));
            
            return MarketParticipantPositionMessage::WireSize;
        }

        inline size_t parseMessage(MWCBDeclineLevelMessage &m, const char* buffer, size_t size, size_t offset) {
            ASSERT((size - offset >= MWCBDeclineLevelMessage::WireSize), "SystemEventMessage buffer < WireSize");
            
            offset += sizeof(MWCBDeclineLevelMessage::MessageType);
            offset += CppHasAnItch::Utils::BigToNative(m.StockLocate, &buffer[offset]);
            offset += CppHasAnItch::Utils::BigToNative(m.TrackingNumber, &buffer[offset]);
            offset += CppHasAnItch::ITCH::ParseToTimestamp(m.Timestamp, &buffer[offset]);
            offset += CppHasAnItch::Utils::BigToNative(m.Level1, &buffer[offset]);
            offset += CppHasAnItch::Utils::BigToNative(m.Level2, &buffer[offset]);
            offset += CppHasAnItch::Utils::BigToNative(m.Level3, &buffer[offset]);
            
            return MWCBDeclineLevelMessage::WireSize;
        }

        inline size_t parseMessage(MWCBStatusMessage &m, const char* buffer, size_t size, size_t offset) {
            ASSERT((size - offset >= MWCBStatusMessage::WireSize), "SystemEventMessage buffer < WireSize");
            
            offset += sizeof(MWCBStatusMessage::MessageType);
            offset += CppHasAnItch::Utils::BigToNative(m.StockLocate, &buffer[offset]);
            offset += CppHasAnItch::Utils::BigToNative(m.TrackingNumber, &buffer[offset]);
            offset += CppHasAnItch::ITCH::ParseToTimestamp(m.Timestamp, &buffer[offset]);
            offset += CppHasAnItch::ITCH::ParseToString(&m.BreachLevel, &buffer[offset], sizeof(m.BreachLevel));
            
            return MWCBStatusMessage::WireSize;
        }

        inline size_t parseMessage(QuotingPeriodUpdateMessage &m, const char* buffer, size_t size, size_t offset) {
            ASSERT((size - offset >= QuotingPeriodUpdateMessage::WireSize), "QuotingPeriodUpdateMessage buffer < WireSize");
            
            offset += sizeof(MWCBStatusMessage::MessageType);
            offset += CppHasAnItch::Utils::BigToNative(m.StockLocate, &buffer[offset]);
            offset += CppHasAnItch::Utils::BigToNative(m.TrackingNumber, &buffer[offset]);
            offset += CppHasAnItch::ITCH::ParseToTimestamp(m.Timestamp, &buffer[offset]);
            offset += CppHasAnItch::ITCH::ParseToString(&m.Stock[0], &buffer[offset], sizeof(m.Stock));
            offset += CppHasAnItch::Utils::BigToNative(m.IPOQuotationReleaseTime, &buffer[offset]);
            offset += CppHasAnItch::ITCH::ParseToString(&m.IPOQuotationReleaseQualifier, &buffer[offset], sizeof(m.IPOQuotationReleaseQualifier));
            offset += CppHasAnItch::Utils::BigToNative(m.IPOPrice, &buffer[offset]);

            return QuotingPeriodUpdateMessage::WireSize;
        }

        inline size_t parseMessage(LULDAuctionCollarMessage &m, const char* buffer, size_t size, size_t offset) {
            ASSERT((size - offset >= LULDAuctionCollarMessage::WireSize), "LULDAuctionCollarMessage buffer < WireSize");
            
            offset += sizeof(LULDAuctionCollarMessage::MessageType);
            offset += CppHasAnItch::Utils::BigToNative(m.StockLocate, &buffer[offset]);
            offset += CppHasAnItch::Utils::BigToNative(m.TrackingNumber, &buffer[offset]);
            offset += CppHasAnItch::ITCH::ParseToTimestamp(m.Timestamp, &buffer[offset]);
            offset += CppHasAnItch::ITCH::ParseToString(&m.Stock[0], &buffer[offset], sizeof(m.Stock));
            offset += CppHasAnItch::Utils::BigToNative(m.AuctionCollarReferencePrice, &buffer[offset]);
            offset += CppHasAnItch::Utils::BigToNative(m.UpperAuctionCollarPrice, &buffer[offset]);
            offset += CppHasAnItch::Utils::BigToNative(m.LowerAuctionCollarPrice, &buffer[offset]);
            offset += CppHasAnItch::Utils::BigToNative(m.AuctionCollarExtension, &buffer[offset]);

            return LULDAuctionCollarMessage::WireSize;
        }

        inline size_t parseMessage(OperationHaltMessage &m, const char* buffer, size_t size, size_t offset) {
            ASSERT((size - offset >= OperationHaltMessage::WireSize), "OperationHaltMessage buffer < WireSize");
            
            offset += sizeof(OperationHaltMessage::MessageType);
            offset += CppHasAnItch::Utils::BigToNative(m.StockLocate, &buffer[offset]);
            offset += CppHasAnItch::Utils::BigToNative(m.TrackingNumber, &buffer[offset]);
            offset += CppHasAnItch::ITCH::ParseToTimestamp(m.Timestamp, &buffer[offset]);
            offset += CppHasAnItch::ITCH::ParseToString(&m.Stock[0], &buffer[offset], sizeof(m.Stock));
            offset += CppHasAnItch::ITCH::ParseToString(&m.MarketCode, &buffer[offset], sizeof(m.MarketCode));
            offset += CppHasAnItch::ITCH::ParseToString(&m.OperationalHaltAction, &buffer[offset], sizeof(m.OperationalHaltAction));

            return OperationHaltMessage::WireSize;
        }

        inline size_t parseMessage(AddOrderMessage &m, const char* buffer, size_t size, size_t offset) {
            ASSERT((size - offset >= AddOrderMessage::WireSize), "AddOrderMessage buffer < WireSize");
            
            offset += sizeof(AddOrderMessage::MessageType);
            offset += CppHasAnItch::Utils::BigToNative(m.StockLocate, &buffer[offset]);
            offset += CppHasAnItch::Utils::BigToNative(m.TrackingNumber, &buffer[offset]);
            offset += CppHasAnItch::ITCH::ParseToTimestamp(m.Timestamp, &buffer[offset]);
            offset += CppHasAnItch::Utils::BigToNative(m.OrderReferenceNumber, &buffer[offset]);
            offset += CppHasAnItch::ITCH::ParseToString(&m.BuySellIndicator, &buffer[offset], sizeof(m.BuySellIndicator));
            offset += CppHasAnItch::ITCH::ParseToString(&m.Shares, &buffer[offset], sizeof(m.Shares));
            offset += CppHasAnItch::ITCH::ParseToString(&m.Stock[0], &buffer[offset], sizeof(m.Stock));
            offset += CppHasAnItch::Utils::BigToNative(m.Price, &buffer[offset]);

            return AddOrderMessage::WireSize;
        }


        inline size_t parseMessage(AddOrderWithMPIDMessage &m, const char* buffer, size_t size, size_t offset) {
            ASSERT((size - offset >= AddOrderWithMPIDMessage::WireSize), "AddOrderWithMPIDMessage buffer < WireSize");
            
            offset += sizeof(AddOrderWithMPIDMessage::MessageType);
            offset += CppHasAnItch::Utils::BigToNative(m.StockLocate, &buffer[offset]);
            offset += CppHasAnItch::Utils::BigToNative(m.TrackingNumber, &buffer[offset]);
            offset += CppHasAnItch::ITCH::ParseToTimestamp(m.Timestamp, &buffer[offset]);
            offset += CppHasAnItch::Utils::BigToNative(m.OrderReferenceNumber, &buffer[offset]);
            offset += CppHasAnItch::ITCH::ParseToString(&m.BuySellIndicator, &buffer[offset], sizeof(m.BuySellIndicator));
            offset += CppHasAnItch::ITCH::ParseToString(&m.Shares, &buffer[offset], sizeof(m.Shares));
            offset += CppHasAnItch::ITCH::ParseToString(&m.Stock[0], &buffer[offset], sizeof(m.Stock));
            offset += CppHasAnItch::Utils::BigToNative(m.Price, &buffer[offset]);
            offset += CppHasAnItch::ITCH::ParseToString(&m.Attribution[0], &buffer[offset], sizeof(m.Attribution));

            return AddOrderWithMPIDMessage::WireSize;
        }

        inline size_t parseMessage(OrderExecutedMessage &m, const char* buffer, size_t size, size_t offset) {
            ASSERT((size - offset >= OrderExecutedMessage::WireSize), "OrderExecutedMessage buffer < WireSize");
            
            offset += sizeof(OrderExecutedMessage::MessageType);
            offset += CppHasAnItch::Utils::BigToNative(m.StockLocate, &buffer[offset]);
            offset += CppHasAnItch::Utils::BigToNative(m.TrackingNumber, &buffer[offset]);
            offset += CppHasAnItch::ITCH::ParseToTimestamp(m.Timestamp, &buffer[offset]);
            offset += CppHasAnItch::Utils::BigToNative(m.OrderReferenceNumber, &buffer[offset]);
            offset += CppHasAnItch::Utils::BigToNative(m.ExecutedShares, &buffer[offset]);
            offset += CppHasAnItch::Utils::BigToNative(m.MatchNumber, &buffer[offset]);

            return AddOrderWithMPIDMessage::WireSize;
        }

        inline size_t parseMessage(OrderExecutedWithPriceMessage &m, const char* buffer, size_t size, size_t offset) {
            ASSERT((size - offset >= OrderExecutedWithPriceMessage::WireSize), "OrderExecutedWithPriceMessage buffer < WireSize");
            
            offset += sizeof(OrderExecutedWithPriceMessage::MessageType);
            offset += CppHasAnItch::Utils::BigToNative(m.StockLocate, &buffer[offset]);
            offset += CppHasAnItch::Utils::BigToNative(m.TrackingNumber, &buffer[offset]);
            offset += CppHasAnItch::ITCH::ParseToTimestamp(m.Timestamp, &buffer[offset]);
            offset += CppHasAnItch::Utils::BigToNative(m.OrderReferenceNumber, &buffer[offset]);
            offset += CppHasAnItch::Utils::BigToNative(m.ExecutedShares, &buffer[offset]);
            offset += CppHasAnItch::Utils::BigToNative(m.MatchNumber, &buffer[offset]);
            offset += CppHasAnItch::ITCH::ParseToString(&m.Printable, &buffer[offset], sizeof(m.Printable));
            offset += CppHasAnItch::Utils::BigToNative(m.ExecutionPrice, &buffer[offset]);

            return OrderExecutedWithPriceMessage::WireSize;
        }

        inline size_t parseMessage(OrderCancelMessage &m, const char* buffer, size_t size, size_t offset) {
            ASSERT((size - offset >= OrderCancelMessage::WireSize), "OrderCancelMessage buffer < WireSize");
            
            offset += sizeof(OrderCancelMessage::MessageType);
            offset += CppHasAnItch::Utils::BigToNative(m.StockLocate, &buffer[offset]);
            offset += CppHasAnItch::Utils::BigToNative(m.TrackingNumber, &buffer[offset]);
            offset += CppHasAnItch::ITCH::ParseToTimestamp(m.Timestamp, &buffer[offset]);
            offset += CppHasAnItch::Utils::BigToNative(m.OrderReferenceNumber, &buffer[offset]);
            offset += CppHasAnItch::Utils::BigToNative(m.CancelledShares, &buffer[offset]);

            return OrderCancelMessage::WireSize;
        }

        inline size_t parseMessage(OrderDeleteMessage &m, const char* buffer, size_t size, size_t offset) {
            ASSERT((size - offset >= OrderDeleteMessage::WireSize), "OrderDeleteMessage buffer < WireSize");
            
            offset += sizeof(OrderDeleteMessage::MessageType);
            offset += CppHasAnItch::Utils::BigToNative(m.StockLocate, &buffer[offset]);
            offset += CppHasAnItch::Utils::BigToNative(m.TrackingNumber, &buffer[offset]);
            offset += CppHasAnItch::ITCH::ParseToTimestamp(m.Timestamp, &buffer[offset]);
            offset += CppHasAnItch::Utils::BigToNative(m.OrderReferenceNumber, &buffer[offset]);

            return OrderDeleteMessage::WireSize;
        }

        inline size_t parseMessage(OrderReplaceMessage &m, const char* buffer, size_t size, size_t offset) {
            ASSERT((size - offset >= OrderReplaceMessage::WireSize), "OrderReplaceMessage buffer < WireSize");
            
            offset += sizeof(OrderReplaceMessage::MessageType);
            offset += CppHasAnItch::Utils::BigToNative(m.StockLocate, &buffer[offset]);
            offset += CppHasAnItch::Utils::BigToNative(m.TrackingNumber, &buffer[offset]);
            offset += CppHasAnItch::ITCH::ParseToTimestamp(m.Timestamp, &buffer[offset]);
            offset += CppHasAnItch::Utils::BigToNative(m.OriginalOrderReferenceNumber, &buffer[offset]);
            offset += CppHasAnItch::Utils::BigToNative(m.NewOrderReferenceNumber, &buffer[offset]);
            offset += CppHasAnItch::Utils::BigToNative(m.Shares, &buffer[offset]);
            offset += CppHasAnItch::Utils::BigToNative(m.Price, &buffer[offset]);

            return OrderReplaceMessage::WireSize;
        }

        inline size_t parseMessage(TradeNonCrossMessage &m, const char* buffer, size_t size, size_t offset) {
            ASSERT((size - offset >= TradeNonCrossMessage::WireSize), "TradeNonCrossMessage buffer < WireSize");
            
            offset += sizeof(TradeNonCrossMessage::MessageType);
            offset += CppHasAnItch::Utils::BigToNative(m.StockLocate, &buffer[offset]);
            offset += CppHasAnItch::Utils::BigToNative(m.TrackingNumber, &buffer[offset]);
            offset += CppHasAnItch::ITCH::ParseToTimestamp(m.Timestamp, &buffer[offset]);
            offset += CppHasAnItch::Utils::BigToNative(m.OrderReferenceNumber, &buffer[offset]);
            offset += CppHasAnItch::ITCH::ParseToString(&m.BuySellIndicator, &buffer[offset], sizeof(m.BuySellIndicator));
            offset += CppHasAnItch::Utils::BigToNative(m.Shares, &buffer[offset]);
            offset += CppHasAnItch::ITCH::ParseToString(&m.Stock[0], &buffer[offset], sizeof(m.Stock));
            offset += CppHasAnItch::Utils::BigToNative(m.Price, &buffer[offset]);
            offset += CppHasAnItch::Utils::BigToNative(m.MatchNumber, &buffer[offset]);

            return TradeNonCrossMessage::WireSize;
        }

        inline size_t parseMessage(TradeCrossMessage &m, const char* buffer, size_t size, size_t offset) {
            ASSERT((size - offset >= TradeCrossMessage::WireSize), "TradeCrossMessage buffer < WireSize");
            
            offset += sizeof(TradeCrossMessage::MessageType);
            offset += CppHasAnItch::Utils::BigToNative(m.StockLocate, &buffer[offset]);
            offset += CppHasAnItch::Utils::BigToNative(m.TrackingNumber, &buffer[offset]);
            offset += CppHasAnItch::ITCH::ParseToTimestamp(m.Timestamp, &buffer[offset]);
            offset += CppHasAnItch::Utils::BigToNative(m.Shares, &buffer[offset]);
            offset += CppHasAnItch::ITCH::ParseToString(&m.Stock[0], &buffer[offset], sizeof(m.Stock));
            offset += CppHasAnItch::Utils::BigToNative(m.CrossPrice, &buffer[offset]);
            offset += CppHasAnItch::Utils::BigToNative(m.MatchNumber, &buffer[offset]);
            offset += CppHasAnItch::ITCH::ParseToString(&m.CrossType, &buffer[offset], sizeof(m.CrossType));

            return TradeCrossMessage::WireSize;
        }

        inline size_t parseMessage(NOIIMessage &m, const char* buffer, size_t size, size_t offset) {
            ASSERT((size - offset >= NOIIMessage::WireSize), "NOIIMessage buffer < WireSize");
            
            offset += sizeof(NOIIMessage::MessageType);
            offset += CppHasAnItch::Utils::BigToNative(m.StockLocate, &buffer[offset]);
            offset += CppHasAnItch::Utils::BigToNative(m.TrackingNumber, &buffer[offset]);
            offset += CppHasAnItch::ITCH::ParseToTimestamp(m.Timestamp, &buffer[offset]);
            offset += CppHasAnItch::Utils::BigToNative(m.PairedShares, &buffer[offset]);
            offset += CppHasAnItch::Utils::BigToNative(m.ImbalanceShares, &buffer[offset]);
            offset += CppHasAnItch::ITCH::ParseToString(&m.ImbalanceDirection, &buffer[offset], sizeof(m.ImbalanceDirection));
            offset += CppHasAnItch::ITCH::ParseToString(&m.Stock[0], &buffer[offset], sizeof(m.Stock));
            offset += CppHasAnItch::Utils::BigToNative(m.FarPrice, &buffer[offset]);
            offset += CppHasAnItch::Utils::BigToNative(m.NearPrice, &buffer[offset]);
            offset += CppHasAnItch::ITCH::ParseToString(&m.CrossType, &buffer[offset], sizeof(m.CrossType));
            offset += CppHasAnItch::ITCH::ParseToString(&m.PriceValidationIndicator, &buffer[offset], sizeof(m.PriceValidationIndicator));

            return NOIIMessage::WireSize;
        }

        inline size_t parseMessage(RPIIMessage &m, const char* buffer, size_t size, size_t offset) {
            ASSERT((size - offset >= RPIIMessage::WireSize), "RPIIMessage buffer < WireSize");
            
            offset += sizeof(NOIIMessage::MessageType);
            offset += CppHasAnItch::Utils::BigToNative(m.StockLocate, &buffer[offset]);
            offset += CppHasAnItch::Utils::BigToNative(m.TrackingNumber, &buffer[offset]);
            offset += CppHasAnItch::ITCH::ParseToTimestamp(m.Timestamp, &buffer[offset]);
            offset += CppHasAnItch::ITCH::ParseToString(&m.Stock[0], &buffer[offset], sizeof(m.Stock));
            offset += CppHasAnItch::ITCH::ParseToString(&m.InterestFlag, &buffer[offset], sizeof(m.InterestFlag));
            
            return RPIIMessage::WireSize;
        }

        inline size_t parseMessage(DLCRPDMessage &m, const char* buffer, size_t size, size_t offset) {
            ASSERT((size - offset >= DLCRPDMessage::WireSize), "DLCRPDMessage buffer < WireSize");
            
            offset += sizeof(NOIIMessage::MessageType);
            offset += CppHasAnItch::Utils::BigToNative(m.StockLocate, &buffer[offset]);
            offset += CppHasAnItch::Utils::BigToNative(m.TrackingNumber, &buffer[offset]);
            offset += CppHasAnItch::ITCH::ParseToTimestamp(m.Timestamp, &buffer[offset]);
            offset += CppHasAnItch::ITCH::ParseToString(&m.Stock[0], &buffer[offset], sizeof(m.Stock));
            offset += CppHasAnItch::ITCH::ParseToString(&m.OpenEligibilityStatus, &buffer[offset], sizeof(m.OpenEligibilityStatus));
            offset += CppHasAnItch::Utils::BigToNative(m.MinimumAllowablePrice, &buffer[offset]);
            offset += CppHasAnItch::Utils::BigToNative(m.MaximumAllowablePrice, &buffer[offset]);
            offset += CppHasAnItch::Utils::BigToNative(m.NearExecutionPrice, &buffer[offset]);
            offset += CppHasAnItch::Utils::BigToNative(m.LowerPriceCollar, &buffer[offset]);
            offset += CppHasAnItch::Utils::BigToNative(m.UpperPriceCollar, &buffer[offset]);
            
            return DLCRPDMessage::WireSize;
        }

        
        



        
        
    }
}