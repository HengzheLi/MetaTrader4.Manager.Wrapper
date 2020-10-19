using System;

namespace P23.MetaTrader4.Manager.Contracts
{
    /// <summary>
    /// Pumping Mode Flags to be used
	/// when calling PumpingSwitchEx method
    /// </summary>
    [Flags]
    public enum PumpingMode
    {
        //--- user flags
        /// <summary>
        /// No flags
        /// </summary>
        Default = 0,

        /// <summary>
        /// do not send ticks
        /// </summary>
        HideTicks = 1,

        /// <summary>
        /// do not send news
        /// </summary>     
        HideNews = 2,

        /// <summary>
        /// do not send mails
        /// </summary> 
        HideMail = 4,

        /// <summary>
        /// send news body with news header in pumping mode
        /// </summary> 
        SendFullNews = 8,   

        /// <summary>
        /// reserved
        /// </summary> 
        Reserved = 16,    
                          
        //--- manager flags

        /// <summary>
        /// do not send online users table
        /// </summary> 
        HideOnline = 32,

        /// <summary>
        /// do not send users table
        /// </summary> 
        HideUsers = 64
    }
}