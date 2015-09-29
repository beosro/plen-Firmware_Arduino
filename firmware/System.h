/*!
	@file      System.h
	@brief     AVR MCUにおける基本機能の管理クラスを提供します。
	@author    Kazuyuki TAKASE
	@copyright The MIT License - http://opensource.org/licenses/mit-license.php
*/

#ifndef _PLEN2__SYSTEM_H_
#define _PLEN2__SYSTEM_H_

#include "Arduino.h"

namespace PLEN2
{
	class System;
}

/*!
	@brief AVR MCUにおける基本機能の管理クラス

	具体的には以下の機能が提供されます。
	- 割り込みのattach，detach
	- 入出力シリアルの管理・提供
*/
class PLEN2::System
{
private:
	//! @brief 動作デバイス
	inline static const char* DEVICE()             { return "PLEN2";   }

	//! @brief コードネーム
	inline static const char* CODENAME()           { return "Cytisus"; }

	//! @brief バージョン番号
	inline static const char* VERSION()            { return "1.1.0";   }

	//! @brief USBシリアルインタフェースの通信速度
	inline static const long  USBSERIAL_BAUDRATE() { return 2000000L;  }
	
	//! @brief BLEシリアルインタフェースの通信速度
	inline static const long  BLESERIAL_BAUDRATE() { return 2000000L;  }

	static Stream* m_input_serial_ptr;  //!< 入力シリアルインスタンスのポインタ
	static Stream* m_output_serial_ptr; //!< 出力シリアルインスタンスのポインタ

public:
	//! @brief MCU内EEPROMのサイズ
	inline static const int INTERNAL_EEPROMSIZE() { return 1024; }

	/*!
		@brief コンストラクタ
	*/
	System();

	/*!
		@brief  USBシリアルインスタンスの取得メソッド

		@return USBシリアルインスタンスの参照
	*/
	Stream& USBSerial();

	/*!
		@brief  BLEシリアルインスタンスの取得メソッド

		@return BLEシリアルインスタンスの参照
	*/
	Stream& BLESerial();

	/*!
		@brief  入力シリアルインスタンスの取得メソッド

		@return 入力シリアルインスタンスの参照

		@attention
		このメソッドにより取得される入力シリアルインスタンスは、
		実行タイミングによって異なる可能性が存在します。
		つまり、戻り値をキャッシュして使い回した際の動作は不定となります。
	*/
	Stream& inputSerial();

	/*!
		@brief  出力シリアルインスタンスの取得メソッド
		
		@return 出力シリアルインスタンスの参照
	*/
	Stream& outputSerial();

	/*!
		@brief 入力シリアルインスタンスの切り替えメソッド
	*/
	void toggleInputSerial();

	/*!
		@brief タイマ1割り込みの許可メソッド
	*/
	void timer1Attach();

	/*!
		@brief タイマ1割り込みの禁止メソッド
	*/
	void timer1Detach();

	/*!
		@brief システム構成のダンプメソッド
	*/
	void dump();
};

#endif // _PLEN2__SYSTEM_H_