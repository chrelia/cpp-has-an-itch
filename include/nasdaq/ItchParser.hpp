
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

    }
    #pragma pack(pop)

    #pragma pack(push, 1)
    struct StockTradingAction {
        
    }

    #pragma pack(pop)



    class ItchParser {
        
        public:
            ItchParser() = default;

        


        inline void parseSystemEventMessage();
    };

};