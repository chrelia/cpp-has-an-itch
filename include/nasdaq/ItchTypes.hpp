#pragma once

#include <cstdint>

namespace Scratch {

    namespace ITCH {

        enum class MessageType {
            SystemEventMessage = 'S',
            StockDirectoryMessage = 'R',
            StockTradingActionMessage = 'H',
            RegSHORestrictionMessage = 'Y',
            MarketParticipantPositionMessage = 'L',
            MWCBDeclineLevelMessage = 'V',
            MWCBStatusMessage = 'W',
            QuotingPeriodUpdateMessage = 'K',
            LULDAuctionCollarMessage = 'J',
            OperationHaltMessage = 'h',
            AddOrderMessage = 'A',
            AddOrderWithMPIDMessage = 'F',
            OrderExecutedMessage = 'E',
            OrderExecutedWithPriceMessage = 'C',
            OrderCancelMessage = 'X',
            OrderDeleteMessage = 'D',
            OrderReplaceMessage = 'U',
            TradeNonCrossMessage = 'P',
            TradeCrossMessage = 'Q',
            BrokenTradeMessage = 'B',
            NOIIMessage = 'I',
            RPIIMessage = 'N',
            DLCRPDMessage = 'O',
        };


        struct SystemEventMessage { 
            char MessageType;
            uint16_t StockLocate;
            uint16_t TrackingNumber;
            uint8_t Timestamp[6];
            char EventCode;

            template <class TOutputStream>
            friend TOutputStream& operator<<(TOutputStream& os, SystemEventMessage& m) {
                os << "{ " 
                << "MessageType : " << m.MessageType << ", "
                << "StockLocate : " << m.StockLocate << ", "
                << "TrackingNumber : " << m.TrackingNumber << ", "
                << "Timestamp : " << m.Timestamp << ", "
                << "EventCode : " << m.EventCode
                << " }";
                return os;
            }
        };
        
        struct StockDirectoryMessage {
            char MessageType;
            uint16_t StockLocate;
            uint16_t TrackingNumber;
            uint8_t Timestamp;
            char Stock[8];
            char MarketCategory;
            char FinancialStatusIndicator;
            uint32_t RoundLotSize;
            char RoundLotsOnly;
            char IssueClassification;
            char IssueSubType[2];
            char Authenticity;
            char ShortSaleThresholdIndicator;
            char IPOFlag;
            char LULDReferencePriceTier;
            char ETPFlag;
            uint32_t ETPLeverageFactor;
            char InverseIndicator;

            template <class TOutputStream>
            friend TOutputStream& operator<<(TOutputStream& os, StockDirectoryMessage& m) {
                os << "{ " 
                << "MessageType : " << m.MessageType << ", "
                << "StockLocate : " << m.StockLocate << ", "
                << "TrackingNumber : " << m.TrackingNumber << ", "
                << "Timestamp : " << m.Timestamp << ", "
                << "Stock : " << m.Stock << ", " 
                << "MarketCategory : " << m.MarketCategory << ", "
                << "FinancialStatusIndicator : " << m.FinancialStatusIndicator << ", "
                << "RoundLotSize : " << m.RoundLotSize << ", " 
                << "IssueClarification : " << m.IssueClassification << ", "
                << "IssueSubType : " << m.IssueSubType << ", "
                << "Authenticity : " << m.Authenticity << ", "
                << "ShortSaleThresholdIndicator : " << m.ShortSaleThresholdIndicator << ", "
                << "IPOFlag : " << m.IPOFlag << ", "
                << "LULDReferencePriceTier : " << m.LULDReferencePriceTier << ", "
                << "ETPFlag : " << m.ETPFlag << ", " 
                << "ETPLeverageFactor : " << m.ETPLeverageFactor
                << " }";

                return os;
            }

        };
        
        struct StockTradingActionMessage {
            char MessageType;
            uint16_t StockLocate;
            uint16_t TrackingNumber;
            uint8_t Timestamp[6];
            char Stock[8];
            char TradingState;
            char Reserved;
            char Reason[4];

            template <class TOutputStream>
            friend TOutputStream& operator<<(TOutputStream& os, StockTradingActionMessage& m) {
                os << "{ " 
                << "MessageType : " << m.MessageType << ", "
                << "StockLocate : " << m.StockLocate << ", "
                << "TrackingNumber : " << m.TrackingNumber << ", "
                << "Timestamp : " << m.Timestamp << ", "
                << "Stock : " << m.Stock << ", "
                << "TradingState : " << m.TradingState << ", "
                << "Reserved : " << m.Reserved << ", " 
                << "Reason : " << m.Reason
                << " }";

                return os;
            }
            
        };
        
        struct RegSHORestrictionMessage {
            char MessageType;
            uint16_t LocateCode;
            uint16_t TrackingNumber;
            uint8_t Timestamp[6];
            char Stock[8];
            char RegSHOAction;

            template <class TOutputStream>
            friend TOutputStream& operator<<(TOutputStream& os, RegSHORestrictionMessage& m) {
                os << "{ " 
                << "MessageType : " << m.MessageType << ", "
                << "LocateCode : " << m.LocateCode << ", "
                << "TrackingNumber : " << m.TrackingNumber << ", "
                << "Timestamp : " << m.Timestamp << ", "
                << "Stock : " << m.Stock << ", "
                << "RegSHOAction : " << m.RegSHOAction
                << " }";

                return os;
            }
            
        };
        
        struct MarketParticipantPositionMessage {
            char MessageType;
            uint16_t StockLocate;
            uint16_t TrackingNumber;
            uint8_t Timestamp[6];
            char MPID[4];
            char Stock[8];
            char PrimaryMarketMaker;
            char MarketMakerMode;
            char MarketParticipantState;

            template <class TOutputStream>
            friend TOutputStream& operator<<(TOutputStream& os, MarketParticipantPositionMessage& m) {
                os << "{ " 
                << "MessageType : " << m.MessageType << ", "
                << "StockLocate : " << m.StockLocate << ", "
                << "TrackingNumber : " << m.TrackingNumber << ", "
                << "Timestamp : " << m.Timestamp << ", "
                << "MPID : " << m.MPID << ", "
                << "Stock : " << m.Stock << ", "
                << "PrimaryMarketMaker : " << m.PrimaryMarketMaker << ", "
                << "MarketMakerMode : " << m.MarketMakerMode << ", "
                << "MarketParticipantState : " << m.MarketParticipantState
                << " }";

                return os;
            }
            
        };
        
        struct MWCBDeclineLevelMessage {
            char MessageType;
            uint16_t StockLocate;
            uint16_t TrackingNumber;
            uint8_t Timestamp[6];
            uint64_t Level1;
            uint64_t Level2;
            uint64_t Level3;

            template <class TOutputStream>
            friend TOutputStream& operator<<(TOutputStream& os, MWCBDeclineLevelMessage& m) {
                os << "{ " 
                << "MessageType : " << m.MessageType << ", "
                << "StockLocate : " << m.StockLocate << ", "
                << "TrackingNumber : " << m.TrackingNumber << ", "
                << "Timestamp : " << m.Timestamp << ", "
                << "Level1 : " << m.Level1 << ", "
                << "Level2 : " << m.Level2 << ", "
                << "Level3 : " << m.Level3
                << " }";

                return os;
            }
            
        };
        
        struct MWCBStatusMessage {
            char MessageType;
            uint16_t StockLocate;
            uint16_t TrackingNumber;
            uint8_t Timestamp[6];
            char BreachLevel;

            template <class TOutputStream>
            friend TOutputStream& operator<<(TOutputStream& os, MWCBStatusMessage& m) {
                os << "{ " 
                << "MessageType : " << m.MessageType << ", "
                << "StockLocate : " << m.StockLocate << ", "
                << "TrackingNumber : " << m.TrackingNumber << ", "
                << "Timestamp : " << m.Timestamp << ", "
                << "BreachLevel : " << m.BreachLevel
                << " }";
                return os;
            }
            
        };
        
        struct QuotingPeriodUpdateMessage {
            char MessageType;
            uint16_t StockLocate;
            uint16_t TrackingNumber;
            uint8_t Timestamp[6];
            char Stock[8];
            uint32_t IPOQuotationReleaseTime;
            char IPOQuotationReleaseQualifier;
            uint32_t IPOPrice;

            template <class TOutputStream>
            friend TOutputStream& operator<<(TOutputStream& os, QuotingPeriodUpdateMessage& m) {
                os << "{ " 
                << "MessageType : " << m.MessageType << ", "
                << "StockLocate : " << m.StockLocate << ", "
                << "TrackingNumber : " << m.TrackingNumber << ", "
                << "Timestamp : " << m.Timestamp << ", "
                << "Stock : " << m.Stock << ", "
                << "IPOQuotationReleaseTime : " << m.IPOQuotationReleaseTime << ", "
                << "IPOQuotationReleaseQualifier : " << m.IPOQuotationReleaseQualifier << ", "
                << "IPOPrice : " << m.IPOPrice
                << " }";
                
                return os;
            }
            
        };
        
        struct LULDAuctionCollarMessage {
            char MessageType;
            uint16_t StockLocate;
            uint16_t TrackingNumber;
            uint8_t Timestamp[6];
            char Stock[8];
            uint32_t AuctionCollarReferencePrice;
            uint32_t UpperAuctionCollarPrice;
            uint32_t LowerAuctionCollarPrice;
            uint32_t AuctionCollarExtension;
            
            template <class TOutputStream>
            friend TOutputStream& operator<<(TOutputStream& os, LULDAuctionCollarMessage& m) {
                os << "{ " 
                << "MessageType : " << m.MessageType << ", "
                << "StockLocate : " << m.StockLocate << ", "
                << "TrackingNumber : " << m.TrackingNumber << ", "
                << "Timestamp : " << m.Timestamp << ", "
                << "Stock : " << m.Stock << ", "
                << "AuctionCollarReferencePrice : " << m.AuctionCollarReferencePrice << ", "
                << "UpperAuctionCollarPrice : " << m.UpperAuctionCollarPrice << ", "
                << "LowerAuctionCollarPrice : " << m.LowerAuctionCollarPrice << ", "
                << "AuctionCollarExtension : " << m.AuctionCollarExtension
                << " }";
                
                
                return os;
            }
            
        };
        
        struct OperationHaltMessage {
            char MessageType;
            uint16_t StockLocate;
            uint16_t TrackingNumber;
            uint8_t Timestamp[6];
            char Stock[8];
            char MarketCode;
            char OperationalHaltAction;
            
            template <class TOutputStream>
            friend TOutputStream& operator<<(TOutputStream& os, OperationHaltMessage& m) {
                os << "{ " 
                << "MessageType : " << m.MessageType << ", "
                << "StockLocate : " << m.StockLocate << ", "
                << "TrackingNumber : " << m.TrackingNumber << ", "
                << "Timestamp : " << m.Timestamp << ", "
                << "Stock : " << m.Stock << ", "
                << "MarketCode : " << m.MarketCode << ", "
                << "OperationalHaltAction : " << m.OperationalHaltAction
                << " }";
                
                
                return os;
            }
            
        };
        
        struct AddOrderMessage {
            char MessageType;
            uint16_t StockLocate;
            uint16_t TrackingNumber;
            uint8_t Timestamp[6];
            uint64_t OrderReferenceNumber;
            char BuySellIndicator;
            char Shares;
            char Stock[8];
            uint32_t Price;

            template <class TOutputStream>
            friend TOutputStream& operator<<(TOutputStream& os, AddOrderMessage& m) {
                os << "{ " 
                << "MessageType : " << m.MessageType << ", "
                << "StockLocate : " << m.StockLocate << ", "
                << "TrackingNumber : " << m.TrackingNumber << ", "
                << "OrderReferenceNumber : " << m.OrderReferenceNumber << ", "
                << "BuySellIndicator : " << m.BuySellIndicator << ", "
                << "Shares : " << m.Shares << ", "
                << "Stock : " << m.Stock << ", "
                << "Price : " << m.Price
                << " }";
                
                
                return os;
            }
            
        };
        
        struct AddOrderWithMPIDMessage {
            char MessageType;
            uint16_t StockLocate;
            uint16_t TrackingNumber;
            uint8_t Timestamp[6];
            uint64_t OrderReferenceNumber;
            char BuySellIndicator;
            char Shares;
            char Stock[8];
            uint32_t Price;
            char Attribution[4];

            template <class TOutputStream>            
            friend TOutputStream& operator<<(TOutputStream& os, AddOrderWithMPIDMessage& m) {
                os << "{ " 
                << "MessageType : " << m.MessageType << ", "
                << "StockLocate : " << m.StockLocate << ", "
                << "TrackingNumber : " << m.TrackingNumber << ", "
                << "OrderReferenceNumber : " << m.OrderReferenceNumber << ", "
                << "BuySellIndicator : " << m.BuySellIndicator << ", "
                << "Shares : " << m.Shares << ", "
                << "Stock : " << m.Stock << ", "
                << "Price : " << m.Price << ", "
                << "Attribution" << m.Attribution
                << " }";
                
                return os;
            }
            
        };
        
        struct OrderExecutedMessage {
            char MessageType;
            uint16_t StockLocate;
            uint16_t TrackingNumber;
            uint8_t Timestamp[6];
            uint64_t OrderReferenceNumber;
            uint32_t ExecutedShares;
            uint64_t MatchNumber;

            template <class TOutputStream>
            friend TOutputStream& operator<<(TOutputStream& os, OrderExecutedMessage& m) {
                os << "{ " 
                << "MessageType : " << m.MessageType << ", "
                << "StockLocate : " << m.StockLocate << ", "
                << "TrackingNumber : " << m.TrackingNumber << ", "
                << "OrderReferenceNumber : " << m.OrderReferenceNumber << ", "
                << "ExecutedShares : " << m.ExecutedShares << ", "
                << "MatchNumber : " << m.MatchNumber
                << " }";
                
                return os;
            }
            
        };
        
        struct OrderExecutedWithPriceMessage {
            char MessageType;
            uint16_t StockLocate;
            uint16_t TrackingNumber;
            uint8_t Timestamp[6];
            uint64_t OrderReferenceNumber;
            uint32_t ExecutedShares;
            uint64_t MatchNumber;
            char Printable;
            uint32_t ExecutionPrice;

            template <class TOutputStream>
            friend TOutputStream& operator<<(TOutputStream& os, OrderExecutedWithPriceMessage& m) {
                os << "{ " 
                << "MessageType : " << m.MessageType << ", "
                << "StockLocate : " << m.StockLocate << ", "
                << "TrackingNumber : " << m.TrackingNumber << ", "
                << "OrderReferenceNumber : " << m.OrderReferenceNumber << ", "
                << "ExecutedShares : " << m.ExecutedShares << ", "
                << "MatchNumber : " << m.MatchNumber << ", "
                << "Printable : " << m.Printable << ", "
                << "ExecutionPrice : " << m.ExecutionPrice
                << " }";
                
                return os;
            }
            
        };
             
        struct OrderCancelMessage {
            char MessageType;
            uint16_t StockLocate;
            uint16_t TrackingNumber;
            uint8_t Timestamp[6];
            uint64_t OrderReferenceNumber;
            uint32_t CancelledShares;
            
            template <class TOutputStream>
            friend TOutputStream& operator<<(TOutputStream& os, OrderCancelMessage& m) {
                os << "{ " 
                << "MessageType : " << m.MessageType << ", "
                << "StockLocate : " << m.StockLocate << ", "
                << "TrackingNumber : " << m.TrackingNumber << ", "
                << "OrderReferenceNumber : " << m.OrderReferenceNumber << ", "
                << "CancelledShares : " << m.CancelledShares
                << " }";
                
                return os;
            }
            
        };
        
        struct OrderDeleteMessage {
            char MessageType;
            uint16_t StockLocate;
            uint16_t TrackingNumber;
            uint8_t Timestamp[6];
            uint64_t OrderReferenceNumber;
            
            template <class TOutputStream>
            friend TOutputStream& operator<<(TOutputStream& os, OrderDeleteMessage& m) {
                os << "{ " 
                << "MessageType : " << m.MessageType << ", "
                << "StockLocate : " << m.StockLocate << ", "
                << "TrackingNumber : " << m.TrackingNumber << ", "
                << "OrderReferenceNumber : " << m.OrderReferenceNumber
                << " }";
                
                return os;
            }
            
        };
        
        struct OrderReplaceMessage {
            char MessageType;
            uint16_t StockLocate;
            uint16_t TrackingNumber;
            uint8_t Timestamp[6];
            uint64_t OriginalOrderReferenceNumber;
            uint64_t NewOrderReferenceNumber;
            uint32_t Shares;
            uint32_t Price;
            
            template <class TOutputStream>
            friend TOutputStream& operator<<(TOutputStream& os, OrderReplaceMessage& m) {
                os << "{ " 
                << "MessageType : " << m.MessageType << ", "
                << "StockLocate : " << m.StockLocate << ", "
                << "TrackingNumber : " << m.TrackingNumber << ", "
                << "Timestamp : " << m.Timestamp << ", "
                << "OriginalOrderReferenceNumber : " << m.OriginalOrderReferenceNumber << ", "
                << "NewOrderReferenceNumber : " << m.NewOrderReferenceNumber << ", "
                << "Shares : " << m.Shares << ", "
                << "Price : " << m.Price
                << " }";
                
                return os;
            }
            
        };
        
        struct TradeNonCrossMessage {
            char MessageType;
            uint16_t StockLocate;
            uint16_t TrackingNumber;
            uint8_t Timestamp[6];
            uint64_t OrderReferenceNumber;
            char BuySellIndicator;
            uint32_t Shares;
            char Stock[8];
            uint32_t Price;
            uint64_t MatchNumber;
            
            template <class TOutputStream>
            friend TOutputStream& operator<<(TOutputStream& os, TradeNonCrossMessage& m) {
                os << "{ " 
                << "MessageType : " << m.MessageType << ", "
                << "StockLocate : " << m.StockLocate << ", "
                << "TrackingNumber : " << m.TrackingNumber << ", "
                << "Timestamp : " << m.Timestamp << ", "
                << "OrderReferenceNumber : " << m.OrderReferenceNumber << ", "
                << "BuySellIndicator : " << m.BuySellIndicator << ", "
                << "Shares : " << m.Shares << ", "
                << "Stock : " << m.Stock << ", "
                << "Price : " << m.Price << ", "
                << "MatchNumber : " << m.MatchNumber
                << " }";
                
                return os;
            }
        };
        
        struct TradeCrossMessage {
            char MessageType;
            uint16_t StockLocate;
            uint16_t TrackingNumber;
            uint8_t Timestamp[6];
            uint64_t Shares;
            char Stock[8];
            uint32_t CrossPrice;
            uint64_t MatchNumber;
            char CrossType;
            
            template <class TOutputStream>
            friend TOutputStream& operator<<(TOutputStream& os, TradeCrossMessage& m) {
                os << "{ " 
                << "MessageType : " << m.MessageType << ", "
                << "StockLocate : " << m.StockLocate << ", "
                << "TrackingNumber : " << m.TrackingNumber << ", "
                << "Timestamp : " << m.Timestamp << ", "
                << "Shares : " << m.Shares << ", "
                << "Stock : " << m.Stock << ", "
                << "CrossPrice : " << m.CrossPrice << ", "
                << "MatchNumber : " << m.MatchNumber << ", "
                << "CrossType : " << m.CrossType
                << " }";
                
                return os;
            }
        };
        
        struct BrokenTradeMessage {
            char MessageType;
            uint16_t StockLocate;
            uint16_t TrackingNumber;
            uint8_t Timestamp[6];
            uint64_t MatchNumber;
            
            template <class TOutputStream>
            friend TOutputStream& operator<<(TOutputStream& os, BrokenTradeMessage& m) {
                os << "{ " 
                << "MessageType : " << m.MessageType << ", "
                << "StockLocate : " << m.StockLocate << ", "
                << "TrackingNumber : " << m.TrackingNumber << ", "
                << "Timestamp : " << m.Timestamp << ", "
                << "MatchNumber : " << m.MatchNumber
                << " }";
                
                return os;
            }
        };
        
        struct NOIIMessage {
            char MessageType;
            uint16_t StockLocate;
            uint16_t TrackingNumber;
            uint8_t Timestamp[6];
            uint64_t PairedShares;
            uint64_t ImbalanceShares;
            char ImbalanceDirection;
            char Stock[8];
            uint32_t FarPrice;
            uint32_t NearPrice;
            uint32_t CurrentReferencePrice;
            char CrossType;
            char PriceValidationIndicator;

            template <class TOutputStream>
            friend TOutputStream& operator<<(TOutputStream& os, NOIIMessage& m) {
                os << "{ " 
                << "MessageType : " << m.MessageType << ", "
                << "StockLocate : " << m.StockLocate << ", "
                << "TrackingNumber : " << m.TrackingNumber << ", "
                << "Timestamp : " << m.Timestamp << ", "
                << "PairedShares : " << m.PairedShares << ", "
                << "ImbalanceShares : " << m.ImbalanceShares << ", "
                << "ImbalanceDirection : " << m.ImbalanceDirection << ", "
                << "Stock : " << m.Stock << ", "
                << "FarPrice : " << m.FarPrice << ", "
                << "NearPrice : " << m.NearPrice << ", "
                << "CurrentReferencePrice : " << m.CurrentReferencePrice << ", "
                << "CrossType : " << m.CrossType << ", "
                << "PriceValidationIndicator : " << m.PriceValidationIndicator
                << " }";
                
                return os;
            }
        };
        
        struct RPIIMessage {
            char MessageType;
            uint16_t StockLocate;
            uint16_t TrackingNumber;
            uint8_t Timestamp[6];
            char Stock[8];
            char InterestFlag;

            template <class TOutputStream>
            friend TOutputStream& operator<<(TOutputStream& os, RPIIMessage& m) {
                os << "{ " 
                << "MessageType : " << m.MessageType << ", "
                << "StockLocate : " << m.StockLocate << ", "
                << "TrackingNumber : " << m.TrackingNumber << ", "
                << "Stock : " << m.Stock << ", "
                << "InterestFlag : " << m.InterestFlag
                << " }";
                
                return os;
            }
        };
        
        // Direct Listing with Capital Raise Price Discovery Message
        struct DLCRPDMessage {
            char MessageType;
            uint16_t StockLocate;
            uint16_t TrackingNumber;
            uint8_t Timestamp[6];
            char Stock[8];
            char OpenEligibilityStatus;
            uint32_t MinimumAllowablePrice;
            uint32_t MaximumAllowablePrice;
            uint64_t NearExecutionPrice;
            uint32_t LowerPriceCollar;
            uint32_t UpperPriceCollar;

            template <class TOutputStream>
            friend TOutputStream& operator<<(TOutputStream& os, DLCRPDMessage& m) {
                os << "{ " 
                << "MessageType : " << m.MessageType << ", "
                << "StockLocate : " << m.StockLocate << ", "
                << "TrackingNumber : " << m.TrackingNumber << ", "
                << "Timestamp : " << m.Timestamp << ", "
                << "Stock : " << m.Stock << ", "
                << "OpenEligibilityStatus : " << m.OpenEligibilityStatus << ", "
                << "MinimumAllowablePrice : " << m.MinimumAllowablePrice << ", "
                << "MaximumAllowablePrice : " << m.MaximumAllowablePrice << ", "
                << "NearExecutionPrice : " << m.NearExecutionPrice << ", "
                << "LowerPriceCollar : " << m.LowerPriceCollar << ", "
                << "UpperPriceCollar : " << m.UpperPriceCollar
                << " }";
                
                return os;
            }
        };
        
    }

}