#pragma once

#include <cstddef>
#include <cstdint>

namespace CppHasAnItch {

    namespace ITCH {

        static constexpr size_t TIMESTAMP_SZ = 48;
        
        struct SystemEventMessage { 
            static constexpr std::size_t WireSize = 12;
            static constexpr char MessageType = 'S';
            uint16_t StockLocate;
            uint16_t TrackingNumber;
            uint64_t Timestamp;
            char EventCode;
        };
        
        struct StockDirectoryMessage {
            static constexpr std::size_t WireSize = 38;
            static constexpr char MessageType = 'R';
            uint16_t StockLocate;
            uint16_t TrackingNumber;
            uint64_t Timestamp;
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
        };
        
        struct StockTradingActionMessage {
            static constexpr std::size_t WireSize = 25;
            static constexpr char MessageType = 'H';
            uint16_t StockLocate;
            uint16_t TrackingNumber;
            uint64_t Timestamp;
            char Stock[8];
            char TradingState;
            char Reserved;
            char Reason[4];            
        };
        
        struct RegSHORestrictionMessage {
            static constexpr std::size_t WireSize = 12;
            static constexpr char MessageType = 'Y';
            uint16_t LocateCode;
            uint16_t TrackingNumber;
            uint64_t Timestamp;
            char Stock[8];
            char RegSHOAction;            
        };
        
        struct MarketParticipantPositionMessage {
            static constexpr std::size_t WireSize = 26;
            static constexpr char MessageType = 'L';
            uint16_t StockLocate;
            uint16_t TrackingNumber;
            uint64_t Timestamp;
            char MPID[4];
            char Stock[8];
            char PrimaryMarketMaker;
            char MarketMakerMode;
            char MarketParticipantState;            
        };
        
        struct MWCBDeclineLevelMessage {
            static constexpr std::size_t WireSize = 35;
            static constexpr char MessageType = 'V';
            uint16_t StockLocate;
            uint16_t TrackingNumber;
            uint64_t Timestamp;
            uint64_t Level1;
            uint64_t Level2;
            uint64_t Level3;
        };
        
        struct MWCBStatusMessage {
            static constexpr std::size_t WireSize = 12;
            static constexpr char MessageType = 'W';
            uint16_t StockLocate;
            uint16_t TrackingNumber;
            uint64_t Timestamp;
            char BreachLevel;
        };
        
        struct QuotingPeriodUpdateMessage {
            static constexpr std::size_t WireSize = 28;
            static constexpr char MessageType = 'K';
            uint16_t StockLocate;
            uint16_t TrackingNumber;
            uint64_t Timestamp;
            char Stock[8];
            uint32_t IPOQuotationReleaseTime;
            char IPOQuotationReleaseQualifier;
            uint32_t IPOPrice;            
        };
        
        struct LULDAuctionCollarMessage {
            static constexpr std::size_t WireSize = 35;
            static constexpr char MessageType = 'J';
            uint16_t StockLocate;
            uint16_t TrackingNumber;
            uint64_t Timestamp;
            char Stock[8];
            uint32_t AuctionCollarReferencePrice;
            uint32_t UpperAuctionCollarPrice;
            uint32_t LowerAuctionCollarPrice;
            uint32_t AuctionCollarExtension;            
        };
        
        struct OperationHaltMessage {
            static constexpr std::size_t WireSize = 21;
            static constexpr char MessageType = 'h';
            uint16_t StockLocate;
            uint16_t TrackingNumber;
            uint64_t Timestamp;
            char Stock[8];
            char MarketCode;
            char OperationalHaltAction;
        };
        
        struct AddOrderMessage {
            static constexpr std::size_t WireSize = 36;
            static constexpr char MessageType = 'A';
            uint16_t StockLocate;
            uint16_t TrackingNumber;
            uint64_t Timestamp;
            uint64_t OrderReferenceNumber;
            char BuySellIndicator;
            char Shares;
            char Stock[8];
            uint32_t Price;            
        };
        
        struct AddOrderWithMPIDMessage {
            static constexpr std::size_t WireSize = 40;
            static constexpr char MessageType = 'F';
            uint16_t StockLocate;
            uint16_t TrackingNumber;
            uint64_t Timestamp;
            uint64_t OrderReferenceNumber;
            char BuySellIndicator;
            char Shares;
            char Stock[8];
            uint32_t Price;
            char Attribution[4];            
        };
        
        struct OrderExecutedMessage {
            static constexpr std::size_t WireSize = 31;
            static constexpr char MessageType = 'E';
            uint16_t StockLocate;
            uint16_t TrackingNumber;
            uint64_t Timestamp;
            uint64_t OrderReferenceNumber;
            uint32_t ExecutedShares;
            uint64_t MatchNumber;
        };
        
        struct OrderExecutedWithPriceMessage {
            static constexpr std::size_t WireSize = 36;
            static constexpr char MessageType = 'C';
            uint16_t StockLocate;
            uint16_t TrackingNumber;
            uint64_t Timestamp;
            uint64_t OrderReferenceNumber;
            uint32_t ExecutedShares;
            uint64_t MatchNumber;
            char Printable;
            uint32_t ExecutionPrice;            
        };
                
        struct OrderCancelMessage {
            static constexpr std::size_t WireSize = 23;
            static constexpr char MessageType = 'X';
            uint16_t StockLocate;
            uint16_t TrackingNumber;
            uint64_t Timestamp;
            uint64_t OrderReferenceNumber;
            uint32_t CancelledShares;
        };
        
        struct OrderDeleteMessage {
            static constexpr std::size_t WireSize = 19;
            static constexpr char MessageType = 'D';
            uint16_t StockLocate;
            uint16_t TrackingNumber;
            uint64_t Timestamp;
            uint64_t OrderReferenceNumber;  
        };
        
        struct OrderReplaceMessage {
            static constexpr std::size_t WireSize = 35;
            static constexpr char MessageType = 'U';
            uint16_t StockLocate;
            uint16_t TrackingNumber;
            uint64_t Timestamp;
            uint64_t OriginalOrderReferenceNumber;
            uint64_t NewOrderReferenceNumber;
            uint32_t Shares;
            uint32_t Price;
        };
        
        struct TradeNonCrossMessage {
            static constexpr std::size_t WireSize = 44;
            static constexpr char MessageType = 'P';
            uint16_t StockLocate;
            uint16_t TrackingNumber;
            uint64_t Timestamp;
            uint64_t OrderReferenceNumber;
            char BuySellIndicator;
            uint32_t Shares;
            char Stock[8];
            uint32_t Price;
            uint64_t MatchNumber;
        };
        
        struct TradeCrossMessage {
            static constexpr std::size_t WireSize = 40;
            static constexpr char MessageType = 'Q';
            uint16_t StockLocate;
            uint16_t TrackingNumber;
            uint64_t Timestamp;
            uint64_t Shares;
            char Stock[8];
            uint32_t CrossPrice;
            uint64_t MatchNumber;
            char CrossType;
        };
        
        struct BrokenTradeMessage {
            static constexpr std::size_t WireSize = 19;
            static constexpr char MessageType = 'B';
            uint16_t StockLocate;
            uint16_t TrackingNumber;
            uint64_t Timestamp;
            uint64_t MatchNumber;
        };
        
        struct NOIIMessage {
            static constexpr std::size_t WireSize = 50;
            static constexpr char MessageType = 'I';
            uint16_t StockLocate;
            uint16_t TrackingNumber;
            uint64_t Timestamp;
            uint64_t PairedShares;
            uint64_t ImbalanceShares;
            char ImbalanceDirection;
            char Stock[8];
            uint32_t FarPrice;
            uint32_t NearPrice;
            uint32_t CurrentReferencePrice;
            char CrossType;
            char PriceValidationIndicator;
        };
        
        struct RPIIMessage {
            static constexpr std::size_t WireSize = 20;
            static constexpr char MessageType = 'N';
            uint16_t StockLocate;
            uint16_t TrackingNumber;
            uint64_t Timestamp;
            char Stock[8];
            char InterestFlag;
        };
        
        // Direct Listing with Capital Raise Price Discovery Message
        struct DLCRPDMessage {
            static constexpr std::size_t WireSize = 48;
            static constexpr char MessageType = 'O';
            uint16_t StockLocate;
            uint16_t TrackingNumber;
            uint64_t Timestamp;
            char Stock[8];
            char OpenEligibilityStatus;
            uint32_t MinimumAllowablePrice;
            uint32_t MaximumAllowablePrice;
            uint64_t NearExecutionPrice;
            uint32_t LowerPriceCollar;
            uint32_t UpperPriceCollar;
        };
    }

}