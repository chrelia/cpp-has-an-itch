
#include <cstdint>
#include <ostream>

namespace itch {


    #pragma pack(push, 1)
    struct SystenEventMessage {
        char MessageType;
        uint16_t StockLocate;
        uint16_t TrackingNumber;
        uint8_t Timestamp[6];
        char EventCode;

        friend std::ostream& operator<<(std::ostream& os, SystenEventMessage& m) {
            os << "MessageType : " << m.MessageType << " "
               << "StockLocate : " << m.StockLocate << " "
               << "TrackingNumber : " << m.TrackingNumber << " "
               << "Timestamp : " << m.Timestamp << " "
               << "EventCode : " << m.EventCode;
            return os;
        }
    };
    #pragma pack(pop)

    #pragma pack(push, 1)
    struct StockDirectory {
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

        friend std::ostream& operator<<(std::ostream& os, StockDirectory& m) {
            os << "MessageType : " << m.MessageType << " "
               << "StockLocate : " << m.StockLocate << " "
               << "TrackingNumber : " << m.TrackingNumber << " "
               << "Timestamp : " << m.Timestamp << " "
               << "Stock : " << m.Stock << " " 
               << "MarketCategory : " << m.MarketCategory << " "
               << "FinancialStatusIndicator : " << m.FinancialStatusIndicator << " "
               << "RoundLotSize : " << m.RoundLotSize << " " 
               << "IssueClarification : " << m.IssueClassification << " "
               << "IssueSubType : " << m.IssueSubType << " "
               << "Authenticity : " << m.Authenticity << " "
               << "ShortSaleThresholdIndicator : " << m.ShortSaleThresholdIndicator << " "
               << "IPOFlag : " << m.IPOFlag << " "
               << "LULDReferencePriceTier : " << m.LULDReferencePriceTier << " "
               << "ETPFlag : " << m.ETPFlag << " " 
               << "ETPLeverageFactor : " << m.ETPLeverageFactor;

            return os;
        }

    };
    #pragma pack(pop)

    #pragma pack(push, 1)
    struct StockTradingAction {
        char MessageType;
        uint16_t StockLocate;
        uint16_t TrackingNumber;
        uint8_t Timestamp[6];
        char Stock[8];
        char TradingState;
        char Reserved;
        char Reason[4];

        friend std::ostream& operator<<(std::ostream& os, StockTradingAction& m) {
            os << "MessageType : " << m.MessageType << " "
               << "StockLocate : " << m.StockLocate << " "
               << "TrackingNumber : " << m.TrackingNumber << " "
               << "Timestamp : " << m.Timestamp << " "
               << "Stock : " << m.Stock << " "
               << "TradingState : " << m.TradingState << " "
               << "Reserved : " << m.Reserved << " " 
               << "Reason : " << m.Reason;

            return os;
        }
        
    };

    #pragma pack(pop)

    #pragma pack(push, 1)
    struct RegSHORestriction {
        char MessageType;
        uint16_t LocateCode;
        uint16_t TrackingNumber;
        uint8_t Timestamp[6];
        char Stock[8];
        char RegSHOAction;

        friend std::ostream& operator<<(std::ostream& os, RegSHORestriction& m) {
            os << "MessageType : " << m.MessageType << " "
               << "LocateCode : " << m.LocateCode << " "
               << "TrackingNumber : " << m.TrackingNumber << " "
               << "Timestamp : " << m.Timestamp << " "
               << "Stock : " << m.Stock << " "
               << "RegSHOAction : " << m.RegSHOAction;

            return os;
        }
        
    };
    #pragma pack(pop)

    #pragma pack(push, 1)
    struct MarketParticipantPosition {
        char MessageType;
        uint16_t StockLocate;
        uint16_t TrackingNumber;
        uint8_t Timestamp[6];
        char MPID[4];
        char Stock[8];
        char PrimaryMarketMaker;
        char MarketMakerMode;
        char MarketParticipantState;

        friend std::ostream& operator<<(std::ostream& os, MarketParticipantPosition& m) {
            os << "MessageType : " << m.MessageType << " "
               << "StockLocate : " << m.StockLocate << " "
               << "TrackingNumber : " << m.TrackingNumber << " "
               << "Timestamp : " << m.Timestamp << " "
               << "MPID : " << m.MPID << " "
               << "Stock : " << m.Stock << " "
               << "PrimaryMarketMaker : " << m.PrimaryMarketMaker << " "
               << "MarketMakerMode : " << m.MarketMakerMode << " "
               << "MarketParticipantState : " << m.MarketParticipantState << " ";

            return os;
        }
        
    };
    #pragma pack(pop)

    #pragma pack(push, 1)
    struct MWCBDeclineLevelMessage {
        char MessageType;
        uint16_t StockLocate;
        uint16_t TrackingNumber;
        uint8_t Timestamp[6];
        uint64_t Level1;
        uint64_t Level2;
        uint64_t Level3;

        friend std::ostream& operator<<(std::ostream& os, MWCBDeclineLevelMessage& m) {
            os << "MessageType : " << m.MessageType << " "
               << "StockLocate : " << m.StockLocate << " "
               << "TrackingNumber : " << m.TrackingNumber << " "
               << "Timestamp : " << m.Timestamp << " "
               << "Level1 : " << m.Level1 << " "
               << "Level2 : " << m.Level2 << " "
               << "Level3 : " << m.Level3;

            return os;
        }
        
    };
    #pragma pack(pop)

    #pragma pack(push, 1)
    struct MWCBStatusMessage {
        char MessageType;
        uint16_t StockLocate;
        uint16_t TrackingNumber;
        uint8_t Timestamp[6];
        char BreachLevel;

        friend std::ostream& operator<<(std::ostream& os, MWCBStatusMessage& m) {
            os << "MessageType : " << m.MessageType << " "
               << "StockLocate : " << m.StockLocate << " "
               << "TrackingNumber : " << m.TrackingNumber << " "
               << "Timestamp : " << m.Timestamp << " "
               << "BreachLevel : " << m.BreachLevel;
            return os;
        }
        
    };
    #pragma pack(pop)

    #pragma pack(push, 1)
    struct QuotingPeriodUpdate {
        char MessageType;
        uint16_t StockLocate;
        uint16_t TrackingNumber;
        uint8_t Timestamp[6];
        char Stock[8];
        uint32_t IPOQuotationReleaseTime;
        char IPOQuotationReleaseQualifier;
        uint32_t IPOPrice;

        friend std::ostream& operator<<(std::ostream& os, QuotingPeriodUpdate& m) {
            os << "MessageType : " << m.MessageType << " "
               << "StockLocate : " << m.StockLocate << " "
               << "TrackingNumber : " << m.TrackingNumber << " "
               << "Timestamp : " << m.Timestamp << " "
               << "Stock : " << m.Stock << " "
               << "IPOQuotationReleaseTime : " << m.IPOQuotationReleaseTime << " "
               << "IPOQuotationReleaseQualifier : " << m.IPOQuotationReleaseQualifier << " "
               << "IPOPrice : " << m.IPOPrice;
            
            return os;
        }
        
    };
    #pragma pack(pop)

    #pragma pack(push, 1)
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
        
        friend std::ostream& operator<<(std::ostream& os, LULDAuctionCollarMessage& m) {
            os << "MessageType : " << m.MessageType << " "
               << "StockLocate : " << m.StockLocate << " "
               << "TrackingNumber : " << m.TrackingNumber << " "
               << "Timestamp : " << m.Timestamp << " "
               << "Stock : " << m.Stock << " "
               << "AuctionCollarReferencePrice : " << m.AuctionCollarReferencePrice << " "
               << "UpperAuctionCollarPrice : " << m.UpperAuctionCollarPrice << " "
               << "LowerAuctionCollarPrice : " << m.LowerAuctionCollarPrice << " "
               << "AuctionCollarExtension : " << m.AuctionCollarExtension;
               
            
            return os;
        }
        
    };
    #pragma pack(pop)

    #pragma pack(push, 1)
    struct OperationHalt {
        char MessageType;
        uint16_t StockLocate;
        uint16_t TrackingNumber;
        uint8_t Timestamp[6];
        char Stock[8];
        char MarketCode;
        char OperationalHaltAction;
        
        friend std::ostream& operator<<(std::ostream& os, OperationHalt& m) {
            os << "MessageType : " << m.MessageType << " "
               << "StockLocate : " << m.StockLocate << " "
               << "TrackingNumber : " << m.TrackingNumber << " "
               << "Timestamp : " << m.Timestamp << " "
               << "Stock : " << m.Stock << " "
               << "MarketCode : " << m.MarketCode << " "
               << "OperationalHaltAction : " << m.OperationalHaltAction;
               
            
            return os;
        }
        
    };
    #pragma pack(pop)

    #pragma pack(push, 1)
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

        
        friend std::ostream& operator<<(std::ostream& os, AddOrderMessage& m) {
            os << "MessageType : " << m.MessageType << " "
               << "StockLocate : " << m.StockLocate << " "
               << "TrackingNumber : " << m.TrackingNumber << " "
               << "OrderReferenceNumber : " << m.OrderReferenceNumber << " "
               << "BuySellIndicator : " << m.BuySellIndicator << " "
               << "Shares : " << m.Shares << " "
               << "Stock : " << m.Stock << " "
               << "Price : " << m.Price;
               
            
            return os;
        }
        
    };
    #pragma pack(pop)

    #pragma pack(push, 1)
    struct AddOrderWithMPIDMessage{
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

        
        friend std::ostream& operator<<(std::ostream& os, AddOrderWithMPIDMessage& m) {
            os << "MessageType : " << m.MessageType << " "
               << "StockLocate : " << m.StockLocate << " "
               << "TrackingNumber : " << m.TrackingNumber << " "
               << "OrderReferenceNumber : " << m.OrderReferenceNumber << " "
               << "BuySellIndicator : " << m.BuySellIndicator << " "
               << "Shares : " << m.Shares << " "
               << "Stock : " << m.Stock << " "
               << "Price : " << m.Price << " "
               << "Attribution" << m.Attribution;
            
            return os;
        }
        
    };
    #pragma pack(pop)

    #pragma pack(push, 1)
    struct OrderExecutedMessage {
        char MessageType;
        uint16_t StockLocate;
        uint16_t TrackingNumber;
        uint8_t Timestamp[6];
        uint64_t OrderReferenceNumber;
        uint32_t ExecutedShares;
        uint64_t MatchNumber;

        
        friend std::ostream& operator<<(std::ostream& os, OrderExecutedMessage& m) {
            os << "MessageType : " << m.MessageType << " "
               << "StockLocate : " << m.StockLocate << " "
               << "TrackingNumber : " << m.TrackingNumber << " "
               << "OrderReferenceNumber : " << m.OrderReferenceNumber << " "
               << "ExecutedShares : " << m.ExecutedShares << " "
               << "MatchNumber : " << m.MatchNumber;
            
            return os;
        }
        
    };
    #pragma pack(pop)


    #pragma pack(push, 1)
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
        
        friend std::ostream& operator<<(std::ostream& os, OrderExecutedWithPriceMessage& m) {
            os << "MessageType : " << m.MessageType << " "
               << "StockLocate : " << m.StockLocate << " "
               << "TrackingNumber : " << m.TrackingNumber << " "
               << "OrderReferenceNumber : " << m.OrderReferenceNumber << " "
               << "ExecutedShares : " << m.ExecutedShares << " "
               << "MatchNumber : " << m.MatchNumber
               << "Printable : " << m.Printable
               << "ExecutionPrice : " << m.ExecutionPrice;
            
            return os;
        }
        
    };
    #pragma pack(pop)

    #pragma pack(push, 1)
    struct OrderCancelMessage {
        char MessageType;
        uint16_t StockLocate;
        uint16_t TrackingNumber;
        uint8_t Timestamp[6];
        uint64_t OrderReferenceNumber;
        uint32_t CancelledShares;
        
        friend std::ostream& operator<<(std::ostream& os, OrderCancelMessage& m) {
            os << "MessageType : " << m.MessageType << " "
               << "StockLocate : " << m.StockLocate << " "
               << "TrackingNumber : " << m.TrackingNumber << " "
               << "OrderReferenceNumber : " << m.OrderReferenceNumber << " "
               << "CancelledShares : " << m.CancelledShares;
            
            return os;
        }
        
    };
    #pragma pack(pop)

    #pragma pack(push, 1)
    struct OrderDeleteMessage {
        char MessageType;
        uint16_t StockLocate;
        uint16_t TrackingNumber;
        uint8_t Timestamp[6];
        uint64_t OrderReferenceNumber;
        
        friend std::ostream& operator<<(std::ostream& os, OrderDeleteMessage& m) {
            os << "MessageType : " << m.MessageType << " "
               << "StockLocate : " << m.StockLocate << " "
               << "TrackingNumber : " << m.TrackingNumber << " "
               << "OrderReferenceNumber : " << m.OrderReferenceNumber;
            
            return os;
        }
        
    };
    #pragma pack(pop)

    #pragma pack(push, 1)
    struct OrderReplaceMessage {
        char MessageType;
        uint16_t StockLocate;
        uint16_t TrackingNumber;
        uint8_t Timestamp[6];
        uint64_t OriginalOrderReferenceNumber;
        uint64_t NewOrderReferenceNumber;
        uint32_t Shares;
        uint32_t Price;
        
        friend std::ostream& operator<<(std::ostream& os, OrderReplaceMessage& m) {
            os << "MessageType : " << m.MessageType << " "
               << "StockLocate : " << m.StockLocate << " "
               << "TrackingNumber : " << m.TrackingNumber << " "
               << "Timestamp : " << m.Timestamp << " "
               << "OriginalOrderReferenceNumber : " << m.OriginalOrderReferenceNumber << " "
               << "NewOrderReferenceNumber : " << m.NewOrderReferenceNumber << " "
               << "Shares : " << m.Shares << " "
               << "Price : " << m.Price;
            
            return os;
        }
        
    };
    #pragma pack(pop)

    #pragma pack(push, 1)
    struct TradeMessageNonCross {
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
        
        friend std::ostream& operator<<(std::ostream& os, TradeMessageNonCross& m) {
            os << "MessageType : " << m.MessageType << " "
               << "StockLocate : " << m.StockLocate << " "
               << "TrackingNumber : " << m.TrackingNumber << " "
               << "Timestamp : " << m.Timestamp << " "
               << "OrderReferenceNumber : " << m.OrderReferenceNumber << " "
               << "BuySellIndicator : " << m.BuySellIndicator << " "
               << "Shares : " << m.Shares << " "
               << "Stock : " << m.Stock << " "
               << "Price : " << m.Price << " "
               << "MatchNumber : " << m.MatchNumber;
            
            return os;
        }
    };
    #pragma pack(pop)

    #pragma pack(push, 1)
    struct TradeMessageCross {
        char MessageType;
        uint16_t StockLocate;
        uint16_t TrackingNumber;
        uint8_t Timestamp[6];
        uint64_t Shares;
        char Stock[8];
        uint32_t CrossPrice;
        uint64_t MatchNumber;
        char CrossType;
        
        friend std::ostream& operator<<(std::ostream& os, TradeMessageCross& m) {
            os << "MessageType : " << m.MessageType << " "
               << "StockLocate : " << m.StockLocate << " "
               << "TrackingNumber : " << m.TrackingNumber << " "
               << "Timestamp : " << m.Timestamp << " "
               << "Shares : " << m.Shares << " "
               << "Stock : " << m.Stock << " "
               << "CrossPrice : " << m.CrossPrice << " "
               << "MatchNumber : " << m.MatchNumber << " "
               << "CrossType : " << m.CrossType;
            
            return os;
        }
    };
    #pragma pack(pop)

    #pragma pack(push, 1)
    struct BrokenTradeMessage {
        char MessageType;
        uint16_t StockLocate;
        uint16_t TrackingNumber;
        uint8_t Timestamp[6];
        uint64_t MatchNumber;
        
        friend std::ostream& operator<<(std::ostream& os, BrokenTradeMessage& m) {
            os << "MessageType : " << m.MessageType << " "
               << "StockLocate : " << m.StockLocate << " "
               << "TrackingNumber : " << m.TrackingNumber << " "
               << "Timestamp : " << m.Timestamp << " "
               << "MatchNumber : " << m.MatchNumber;
            
            return os;
        }
    };
    #pragma pack(pop)

    #pragma pack(push, 1)
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

        
        friend std::ostream& operator<<(std::ostream& os, NOIIMessage& m) {
            os << "MessageType : " << m.MessageType << " "
               << "StockLocate : " << m.StockLocate << " "
               << "TrackingNumber : " << m.TrackingNumber << " "
               << "Timestamp : " << m.Timestamp << " "
               << "PairedShares : " << m.PairedShares << " "
               << "ImbalanceShares : " << m.ImbalanceShares << " "
               << "ImbalanceDirection : " << m.ImbalanceDirection << " "
               << "Stock : " << m.Stock << " "
               << "FarPrice : " << m.FarPrice << " "
               << "NearPrice : " << m.NearPrice << " "
               << "CurrentReferencePrice : " << m.CurrentReferencePrice << " "
               << "CrossType : " << m.CrossType << " "
               << "PriceValidationIndicator : " << m.PriceValidationIndicator;
            
            return os;
        }
    };
    #pragma pack(pop)

    #pragma pack(push, 1)
    struct RPIIMessage {
        char MessageType;
        uint16_t StockLocate;
        uint16_t TrackingNumber;
        uint8_t Timestamp[6];
        char Stock[8];
        char InterestFlag;

        
        friend std::ostream& operator<<(std::ostream& os, RPIIMessage& m) {
            os << "MessageType : " << m.MessageType << " "
               << "StockLocate : " << m.StockLocate << " "
               << "TrackingNumber : " << m.TrackingNumber << " "
               << "Stock : " << m.Stock << " "
               << "InterestFlag : " << m.InterestFlag;
            
            return os;
        }
    };
    #pragma pack(pop)

    #pragma pack(push, 1)
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

        
        friend std::ostream& operator<<(std::ostream& os, DLCRPDMessage& m) {
            os << "MessageType : " << m.MessageType << " "
               << "StockLocate : " << m.StockLocate << " "
               << "TrackingNumber : " << m.TrackingNumber << " "
               << "Timestamp : " << m.Timestamp << " "
               << "Stock : " << m.Stock << " "
               << "OpenEligibilityStatus : " << m.OpenEligibilityStatus << " "
               << "MinimumAllowablePrice : " << m.MinimumAllowablePrice << " "
               << "MaximumAllowablePrice : " << m.MaximumAllowablePrice << " "
               << "NearExecutionPrice : " << m.NearExecutionPrice << " "
               << "LowerPriceCollar : " << m.LowerPriceCollar << " "
               << "UpperPriceCollar : " << m.UpperPriceCollar;
            
            return os;
        }
    };
    #pragma pack(pop)
    

    class ItchParser {
        
        public:
            ItchParser() = default;

        


        inline void parseSystemEventMessage();
    };

};