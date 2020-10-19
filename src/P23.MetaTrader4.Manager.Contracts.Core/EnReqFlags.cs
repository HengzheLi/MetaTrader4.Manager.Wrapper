using System;

namespace P23.MetaTrader4.Manager.Contracts
{
	/// <summary>
	/// Trade request flags
	/// </summary>
	[Flags]
	public enum EnReqFlags
	{
		/// <summary>
		/// No flags
		/// </summary>
		None = 0x00000000,
		/// <summary>
		/// Placed by signal
		/// </summary>
		Signal = 0x00000001,
		/// <summary>
		/// Placed by expert
		/// </summary>
		Expert = 0x00000002,
		/// <summary>
		/// Placed by gateway
		/// </summary>
		Gateway = 0x00000004,
		/// <summary>
		/// Placed by mobile terminal
		/// </summary>
		Mobile = 0x00000008,
		/// <summary>
		/// Placed by web terminal
		/// </summary>
		Web = 0x00000010,
		/// <summary>
		/// Placed by api
		/// </summary>
		Api = 0x00000020
	}
}
