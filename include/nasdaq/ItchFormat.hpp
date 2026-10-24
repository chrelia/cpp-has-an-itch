#pragma once

#include "nasdaq/ItchTypes.hpp"
#include "utils/Endian.hpp"
#include <cstring>
#include <string>

// will use sso for stack allocation to convert char[] to string
// no heap
#define write_str(val) \
    std::string(val, sizeof(val)) \

namespace CppHasAnItch {

  namespace ITCH {

    template <class TOutputStream>
    inline TOutputStream& operator<<(TOutputStream& os, SystemEventMessage& m) {
        os << "{ " 
        << "MessageType : " << m.MessageType << ", "
        << "StockLocate : " << m.StockLocate << ", "
        << "TrackingNumber : " << m.TrackingNumber << ", "
        << "Timestamp : " << m.Timestamp << ", "
        << "EventCode : " << m.EventCode
        << " }";
        return os;
    }

    template <class TOutputStream>
    inline TOutputStream& operator<<(TOutputStream& os, StockDirectoryMessage& m) {
        os << "{ " 
        << "MessageType : " << m.MessageType << ", "
        << "StockLocate : " << m.StockLocate << ", "
        << "TrackingNumber : " << m.TrackingNumber << ", "
        << "Timestamp : " << m.Timestamp << ", "
        << "Stock : " << write_str(m.Stock) << ", " 
        << "MarketCategory : " << write_str(m.MarketCategory) << ", "
        << "FinancialStatusIndicator : " << m.FinancialStatusIndicator << ", "
        << "RoundLotSize : " << m.RoundLotSize << ", " 
        << "IssueClarification : " << m.IssueClassification << ", "
        << "IssueSubType : " << write_str(m.IssueSubType) << ", "
        << "Authenticity : " << m.Authenticity << ", "
        << "ShortSaleThresholdIndicator : " << m.ShortSaleThresholdIndicator << ", "
        << "IPOFlag : " << m.IPOFlag << ", "
        << "LULDReferencePriceTier : " << m.LULDReferencePriceTier << ", "
        << "ETPFlag : " << m.ETPFlag << ", " 
        << "ETPLeverageFactor : " << m.ETPLeverageFactor
        << " }";

        return os;
    }

    template <class TOutputStream>
    inline TOutputStream& operator<<(TOutputStream& os, StockTradingActionMessage& m) {
        os << "{ " 
        << "MessageType : " << m.MessageType << ", "
        << "StockLocate : " << m.StockLocate << ", "
        << "TrackingNumber : " << m.TrackingNumber << ", "
        << "Timestamp : " << m.Timestamp << ", "
        << "Stock : " << write_str(m.Stock) << ", "
        << "TradingState : " << m.TradingState << ", "
        << "Reserved : " << m.Reserved << ", " 
        << "Reason : " << write_str(m.Reason)
        << " }";

        return os;
    }

    template <class TOutputStream>
    inline TOutputStream& operator<<(TOutputStream& os, RegSHORestrictionMessage& m) {
        os << "{ " 
        << "MessageType : " << m.MessageType << ", "
        << "LocateCode : " << m.LocateCode << ", "
        << "TrackingNumber : " << m.TrackingNumber << ", "
        << "Timestamp : " << m.Timestamp << ", "
        << "Stock : " << write_str(m.Stock) << ", "
        << "RegSHOAction : " << m.RegSHOAction
        << " }";

        return os;
    }

    template <class TOutputStream>
    inline TOutputStream& operator<<(TOutputStream& os, MarketParticipantPositionMessage& m) {
        os << "{ " 
        << "MessageType : " << m.MessageType << ", "
        << "StockLocate : " << m.StockLocate << ", "
        << "TrackingNumber : " << m.TrackingNumber << ", "
        << "Timestamp : " << m.Timestamp << ", "
        << "MPID : " << write_str(m.MPID) << ", "
        << "Stock : " << write_str(m.Stock) << ", "
        << "PrimaryMarketMaker : " << m.PrimaryMarketMaker << ", "
        << "MarketMakerMode : " << m.MarketMakerMode << ", "
        << "MarketParticipantState : " << m.MarketParticipantState
        << " }";

        return os;
    }

    template <class TOutputStream>
    inline TOutputStream& operator<<(TOutputStream& os, MWCBDeclineLevelMessage& m) {
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

    template <class TOutputStream>
    inline TOutputStream& operator<<(TOutputStream& os, MWCBStatusMessage& m) {
        os << "{ " 
        << "MessageType : " << m.MessageType << ", "
        << "StockLocate : " << m.StockLocate << ", "
        << "TrackingNumber : " << m.TrackingNumber << ", "
        << "Timestamp : " << m.Timestamp << ", "
        << "BreachLevel : " << m.BreachLevel
        << " }";
        return os;
    }
        
    template <class TOutputStream>
    inline TOutputStream& operator<<(TOutputStream& os, QuotingPeriodUpdateMessage& m) {
        os << "{ " 
        << "MessageType : " << m.MessageType << ", "
        << "StockLocate : " << m.StockLocate << ", "
        << "TrackingNumber : " << m.TrackingNumber << ", "
        << "Timestamp : " << m.Timestamp << ", "
        << "Stock : " << write_str(m.Stock) << ", "
        << "IPOQuotationReleaseTime : " << m.IPOQuotationReleaseTime << ", "
        << "IPOQuotationReleaseQualifier : " << m.IPOQuotationReleaseQualifier << ", "
        << "IPOPrice : " << m.IPOPrice
        << " }";
        
        return os;
    }


    template <class TOutputStream>
    inline TOutputStream& operator<<(TOutputStream& os, LULDAuctionCollarMessage& m) {
        os << "{ " 
        << "MessageType : " << m.MessageType << ", "
        << "StockLocate : " << m.StockLocate << ", "
        << "TrackingNumber : " << m.TrackingNumber << ", "
        << "Timestamp : " << m.Timestamp << ", "
        << "Stock : " << write_str(m.Stock) << ", "
        << "AuctionCollarReferencePrice : " << m.AuctionCollarReferencePrice << ", "
        << "UpperAuctionCollarPrice : " << m.UpperAuctionCollarPrice << ", "
        << "LowerAuctionCollarPrice : " << m.LowerAuctionCollarPrice << ", "
        << "AuctionCollarExtension : " << m.AuctionCollarExtension
        << " }";
        
        
        return os;
    }

    template <class TOutputStream>
    inline TOutputStream& operator<<(TOutputStream& os, OperationHaltMessage& m) {
        os << "{ " 
        << "MessageType : " << m.MessageType << ", "
        << "StockLocate : " << m.StockLocate << ", "
        << "TrackingNumber : " << m.TrackingNumber << ", "
        << "Timestamp : " << m.Timestamp << ", "
        << "Stock : " << write_str(m.Stock) << ", "
        << "MarketCode : " << m.MarketCode << ", "
        << "OperationalHaltAction : " << m.OperationalHaltAction
        << " }";
        
        
        return os;
    }

    template <class TOutputStream>
    inline TOutputStream& operator<<(TOutputStream& os, AddOrderMessage& m) {
        os << "{ " 
        << "MessageType : " << m.MessageType << ", "
        << "StockLocate : " << m.StockLocate << ", "
        << "TrackingNumber : " << m.TrackingNumber << ", "
        << "OrderReferenceNumber : " << m.OrderReferenceNumber << ", "
        << "BuySellIndicator : " << m.BuySellIndicator << ", "
        << "Shares : " << m.Shares << ", "
        << "Stock : " << write_str(m.Stock) << ", "
        << "Price : " << m.Price
        << " }";
        
        
        return os;
    }

    template <class TOutputStream>            
    inline TOutputStream& operator<<(TOutputStream& os, AddOrderWithMPIDMessage& m) {
        os << "{ " 
        << "MessageType : " << m.MessageType << ", "
        << "StockLocate : " << m.StockLocate << ", "
        << "TrackingNumber : " << m.TrackingNumber << ", "
        << "OrderReferenceNumber : " << m.OrderReferenceNumber << ", "
        << "BuySellIndicator : " << m.BuySellIndicator << ", "
        << "Shares : " << m.Shares << ", "
        << "Stock : " << write_str(m.Stock) << ", "
        << "Price : " << m.Price << ", "
        << "Attribution" << write_str(m.Attribution)
        << " }";
        
        return os;
    }
    template <class TOutputStream>
    inline TOutputStream& operator<<(TOutputStream& os, OrderExecutedMessage& m) {
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

    template <class TOutputStream>
    inline TOutputStream& operator<<(TOutputStream& os, OrderExecutedWithPriceMessage& m) {
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

    template <class TOutputStream>
    inline TOutputStream& operator<<(TOutputStream& os, OrderCancelMessage& m) {
        os << "{ " 
        << "MessageType : " << m.MessageType << ", "
        << "StockLocate : " << m.StockLocate << ", "
        << "TrackingNumber : " << m.TrackingNumber << ", "
        << "OrderReferenceNumber : " << m.OrderReferenceNumber << ", "
        << "CancelledShares : " << m.CancelledShares
        << " }";
        
        return os;
    }

    template <class TOutputStream>
    inline TOutputStream& operator<<(TOutputStream& os, OrderDeleteMessage& m) {
        os << "{ " 
        << "MessageType : " << m.MessageType << ", "
        << "StockLocate : " << m.StockLocate << ", "
        << "TrackingNumber : " << m.TrackingNumber << ", "
        << "OrderReferenceNumber : " << m.OrderReferenceNumber
        << " }";
        
        return os;
    }

    template <class TOutputStream>
    inline TOutputStream& operator<<(TOutputStream& os, OrderReplaceMessage& m) {
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

    template <class TOutputStream>
    inline TOutputStream& operator<<(TOutputStream& os, TradeNonCrossMessage& m) {
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

    template <class TOutputStream>
    inline TOutputStream& operator<<(TOutputStream& os, TradeCrossMessage& m) {
        os << "{ " 
        << "MessageType : " << m.MessageType << ", "
        << "StockLocate : " << m.StockLocate << ", "
        << "TrackingNumber : " << m.TrackingNumber << ", "
        << "Timestamp : " << m.Timestamp << ", "
        << "Shares : " << m.Shares << ", "
        << "Stock : " << write_str(m.Stock) << ", "
        << "CrossPrice : " << m.CrossPrice << ", "
        << "MatchNumber : " << m.MatchNumber << ", "
        << "CrossType : " << m.CrossType
        << " }";
        
        return os;
    }

    template <class TOutputStream>
    inline TOutputStream& operator<<(TOutputStream& os, BrokenTradeMessage& m) {
        os << "{ " 
        << "MessageType : " << m.MessageType << ", "
        << "StockLocate : " << write_str(m.StockLocate) << ", "
        << "TrackingNumber : " << m.TrackingNumber << ", "
        << "Timestamp : " << m.Timestamp << ", "
        << "MatchNumber : " << m.MatchNumber
        << " }";
        
        return os;
    }

    template <class TOutputStream>
    inline TOutputStream& operator<<(TOutputStream& os, NOIIMessage& m) {
        os << "{ " 
        << "MessageType : " << m.MessageType << ", "
        << "StockLocate : " << m.StockLocate << ", "
        << "TrackingNumber : " << m.TrackingNumber << ", "
        << "Timestamp : " << m.Timestamp << ", "
        << "PairedShares : " << m.PairedShares << ", "
        << "ImbalanceShares : " << m.ImbalanceShares << ", "
        << "ImbalanceDirection : " << m.ImbalanceDirection << ", "
        << "Stock : " << write_str(m.Stock) << ", "
        << "FarPrice : " << m.FarPrice << ", "
        << "NearPrice : " << m.NearPrice << ", "
        << "CurrentReferencePrice : " << m.CurrentReferencePrice << ", "
        << "CrossType : " << m.CrossType << ", "
        << "PriceValidationIndicator : " << m.PriceValidationIndicator
        << " }";
        
        return os;
    }

    template <class TOutputStream>
    inline TOutputStream& operator<<(TOutputStream& os, RPIIMessage& m) {
        os << "{ " 
        << "MessageType : " << m.MessageType << ", "
        << "StockLocate : " << m.StockLocate << ", "
        << "TrackingNumber : " << m.TrackingNumber << ", "
        << "Stock : " << write_str(m.Stock) << ", "
        << "InterestFlag : " << m.InterestFlag
        << " }";
        
        return os;
    }

    template <class TOutputStream>
    inline TOutputStream& operator<<(TOutputStream& os, DLCRPDMessage& m) {
        os << "{ " 
        << "MessageType : " << m.MessageType << ", "
        << "StockLocate : " << m.StockLocate << ", "
        << "TrackingNumber : " << m.TrackingNumber << ", "
        << "Timestamp : " << m.Timestamp << ", "
        << "Stock : " << write_str(m.Stock) << ", "
        << "OpenEligibilityStatus : " << write_str(m.OpenEligibilityStatus) << ", "
        << "MinimumAllowablePrice : " << m.MinimumAllowablePrice << ", "
        << "MaximumAllowablePrice : " << m.MaximumAllowablePrice << ", "
        << "NearExecutionPrice : " << m.NearExecutionPrice << ", "
        << "LowerPriceCollar : " << m.LowerPriceCollar << ", "
        << "UpperPriceCollar : " << m.UpperPriceCollar
        << " }";
        
        return os;
    }

    inline size_t ParseToTimestamp(uint64_t &val, const char* buffer) {
        auto res = CppHasAnItch::Utils::BigToNative(val, buffer);
        val = val >> 16;
        return TIMESTAMP_BYTE_SZ;
    }

  }
}