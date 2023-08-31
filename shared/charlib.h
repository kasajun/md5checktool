#if _MSC_VER > 1000
#pragma once
#endif

#ifndef __CHARLIB_H_5432069E_5D43_445e_9560_EB0C8D0C7998__
#define __CHARLIB_H_5432069E_5D43_445e_9560_EB0C8D0C7998__

#include "targetver.h"
#include <Windows.h>
#include <stdio.h>
#include <wchar.h>
#include <limits.h>
#include <time.h>

#ifndef WCHAR
typedef wchar_t WCHAR;
#endif

#ifndef QWORD
typedef unsigned __int64 QWORD;
#endif

#if _MSC_VER < 1400
#define _NODLL 1
#endif

#ifndef SIZEOF_NUM
#define SIZEOF_NUM(A) (sizeof(A) / sizeof((A)[0]))
#endif

#if _MSC_VER > 1300
#define STRCPY_FUNC(D, N, S) strcpy_s((D), (N), (S))
#define WCSCPY_FUNC(D, N, S) wcscpy_s((D), (N), (S))
#define TCSCPY_FUNC(D, N, S) _tcscpy_s((D), (N), (S))
#define STRCAT_FUNC(D, N, S) strcat_s((D), (N), (S))
#define WCSCAT_FUNC(D, N, S) wcscat_s((D), (N), (S))
#define TCSCAT_FUNC(D, N, S) _tcscat_s((D), (N), (S))
#define SPRINTF_FUNC _sprintf_s
#define SWPRINTF_FUNC _swprintf_s
#define STPRINTF_FUNC _stprintf_s
#define SSCANF_FUNC _sscanf_s
#define SWSCANF_FUNC _swscanf_s
#define STSCANF_FUNC _stscanf_s
#define ITOA_FUNC _itoa_s
#define ITOW_FUNC _itow_s
#define ITOT_FUNC _itot_s
#define I64TOA_FUNC(I, S, N, R) _i64toa_s(I, S, N, R)
#define I64TOW_FUNC(I, S, N, R) _i64tow_s(I, S, N, R)
#define I64TOT_FUNC(I, S, N, R) _i64tot_s(I, S, N, R)
#define TCSUPR_FUNC _tcsupr_s
#define TCSLWR_FUNC _tcslwr_s
#else
#define STRCPY_FUNC(D, N, S) strncpy((D), (S), (N))
#define WCSCPY_FUNC(D, N, S) wcsncpy((D), (S), (N))
#define TCSCPY_FUNC(D, N, S) _tcsncpy((D), (S), (N))
#define STRCAT_FUNC(D, N, S) strncat((D), (S), (N))
#define WCSCAT_FUNC(D, N, S) wcsncat((D), (S), (N))
#define TCSCAT_FUNC(D, N, S) _tcsncat((D), (S), (N))
#define SPRINTF_FUNC _sprintf
#define SWPRINTF_FUNC _swprintf
#define STPRINTF_FUNC _stprintf
#define SSCANF_FUNC _sscanf
#define SWSCANF_FUNC _swscanf
#define STSCANF_FUNC _stscanf
#define ITOA_FUNC _itoa
#define ITOW_FUNC _itow
#define ITOT_FUNC _itot
#define I64TOA_FUNC(I, S, N, R) _i64toa(I, S, R)
#define I64TOW_FUNC(I, S, N, R) _i64tow(I, S, R)
#define I64TOT_FUNC(I, S, N, R) _i64tot(I, S, R)
#define TCSUPR_FUNC _tcsupr
#define TCSLWR_FUNC _tcslwr


typedef long __time64_t;
typedef size_t errno_t;

size_t strcpy_s(char* _Dst, size_t _DstSize, const char* _Src);
size_t wcscpy_s(WCHAR* _Dst, size_t _DstSize, const WCHAR* _Src);
int sprintf_s(char* _Dst, size_t _SizeInWords, const char* _Format, ...);
int _swprintf_s(WCHAR* _Dst, size_t _SizeInWords, const WCHAR* _Format, ...);
size_t _itoa_s(int _Val, char* _DstBuf, size_t _SizeInWords, int _Radix);
size_t _itow_s(int _Val, WCHAR* _DstBuf, size_t _SizeInWords, int _Radix);
size_t _ltoa_s(long _Val, char* _DstBuf, size_t _SizeInWords, int _Radix);
size_t _ltow_s(long _Val, WCHAR* _DstBuf, size_t _SizeInWords, int _Radix);
size_t _ultoa_s(unsigned long _Val, char* _DstBuf, size_t _SizeInWords, int _Radix);
size_t _ultow_s(unsigned long _Val, WCHAR* _DstBuf, size_t _SizeInWords, int _Radix);
size_t _i64toa_s(__int64 _Val, char* _DstBuf, size_t _SizeInWords, int _Radix);
size_t _i64tow_s(__int64 _Val, WCHAR* _DstBuf, size_t _SizeInWords, int _Radix);
size_t _ui64toa_s(unsigned __int64 _Val, char* _DstBuf, size_t _SizeInWords, int _Radix);
size_t _ui64tow_s(unsigned __int64 _Val, WCHAR* _DstBuf, size_t _SizeInWords, int _Radix);

#ifdef _UNICODE
#define _stprintf_s	_swprintf_s
#define _tcscpy_s	wcscpy_s
#define _itot_s		_itow_s
#define _ltot_s     _ltow_s
#define _ultot_s    _ultow_s
#define _i64tot_s	_i64tow_s
#define _ui64tot_s	_ui64tow_s
#else
#define _stprintf_s	sprintf_s
#define _tcscpy_s	strcpy_s
#define _itot_s		_itoa_s
#define _ltot_s		_ltoa_s
#define _ultot_s	_ultoa_s
#define _i64tot_s	_i64toa_s
#define _ui64tot_s	_ui64toa_s
#endif

void __cpuid(int* cpuInfo, int function_id);
unsigned __int64 __rdtsc();

#ifndef CHAR_MIN
#define CHAR_MIN -12
#endif
#ifndef CHAR_MAX
#define CHAR_MAX 127
#endif
#ifndef SIZE_MAX
#define SIZE_MAX 0xFFFFFFFF
#endif
#endif

#if _MSC_VER < 1600
#if !defined(_M_IX86)
extern "C" {
#endif
	void __cpuidex(int* cpuInfo, int function_id, int subfunction_id);
#if !defined(_M_IX86)
}
#endif
#endif

#ifdef _DEBUG
#define DEBUG_OUT_STRING OutputDebugString
#else
#define DEBUG_OUT_STRING ((void)0)
#endif

#if _MSC_VER < 1600
void* _AlignedMalloc(size_t s, size_t align = 16);
void _AlignedFree(void* p);
#else
#define _AlignedMalloc _aligned_malloc
#define _AlignedFree _aligned_free
#endif

char* qstrcpy(char* _Destination, const char* _Source);
char* qstrncpy(char* _Destination, const char* _Source, size_t _Count);
WCHAR* qwcscpy(WCHAR* _Destination, const WCHAR* _Source);
WCHAR* qwcsncpy(WCHAR* _Destination, const WCHAR* _Source, size_t _Count);

unsigned __int64 FILEToFileSize(FILE* pInFilePointer);
unsigned __int64 CharToFileSize(const char* cpInFileName);
unsigned __int64 WCharToFileSize(const WCHAR* cpInFileName);


#ifndef qtcscpy
#ifdef _UNICODE
#define qtcscpy qwcscpy
#define qtcsncpy qwcsncpy
#else
#define qtcscpy qstrcpy
#define qtcsncpy qstrncpy
#endif
#endif



size_t BinaryToFileA(const void* cpInBinary, const char* cpInFileName, size_t inSize);
size_t BinaryToFileW(const void* cpInBinary, const WCHAR* cpInFileName, size_t inSize);

size_t CharToFileA(const char* cpInChar, const char* cpInFileName, size_t inSize);
size_t CharToFileW(const char* cpInChar, const WCHAR* cpInFileName, size_t inSize);

size_t CharToFileA(const char* cpInChar, const char* cpInFileName);
size_t CharToFileW(const char* cpInChar, const WCHAR* cpInFileName);

size_t CharToCharFileA(const char* cpInChar, const char* cpInFileName);
size_t CharToCharFileW(const char* cpInChar, const WCHAR* cpInFileName);

size_t CharToWCharFileA(const char* cpInChar, const char* cpInFileName);
size_t CharToWCharFileW(const char* cpInChar, const WCHAR* cpInFileName);

size_t CharToUtf8CharFileA(const char* cpInChar, const char* cpInFileName);
size_t CharToUtf8CharFileW(const char* cpInChar, const WCHAR* cpInFileName);

size_t WCharToCharFileA(const WCHAR* cpInWChar, const char* cpInFileName);
size_t WCharToCharFileW(const WCHAR* cpInWChar, const WCHAR* cpInFileName);

size_t WCharToWCharFileA(const WCHAR* cpInWChar, const char* cpInFileName);
size_t WCharToWCharFileW(const WCHAR* cpInWChar, const WCHAR* cpInFileName);

size_t WCharToUtf8CharFileA(const WCHAR* cpInWChar, const char* cpInFileName);
size_t WCharToUtf8CharFileW(const WCHAR* cpInWChar, const WCHAR* cpInFileName);

size_t qmbslen(const char* cpInChar);

int qwctomb(char* pDst, const wchar_t* pSrc);
int qmbtowc(wchar_t* pDst, const char* pSrc);

char* CharToCharConv(const char* cpInChar, char* pOutChar = NULL);
size_t CharToCharLength(const char* cpInChar);

WCHAR* CharToWCharConv(const char* cpInChar, WCHAR* pOutWChar = NULL);
size_t CharToWCharLength(const char* cpInChar);

char* WCharToCharConv(const WCHAR* cpInWChar, char* pOutChar = NULL);
size_t WCharToCharLength(const WCHAR* cpInWChar);

WCHAR* WCharToWCharConv(const WCHAR* cpInWChar, WCHAR* pOutWChar = NULL);
size_t WCharToWCharLength(const WCHAR* cpInWChar);

char* CharToUtf8CharConv(const char* cpInChar, char* pOutUtf8Char = NULL);
size_t CharToUtf8CharLength(const char* cpInChar);

char* Utf8CharToCharConv(const char* cpInUtf8Char, char* pOutChar = NULL);
size_t Utf8CharToCharLength(const char* cpInUtf8Char);

char* WCharToUtf8CharConv(const WCHAR* cpInWChar, char* pOutUtf8Char = NULL);
size_t WCharToUtf8CharLength(const WCHAR* cpInWChar);

WCHAR* Utf8CharToWCharConv(const char* cpInUtf8Char, WCHAR* pOutWChar = NULL);
size_t Utf8CharToWCharLength(const char* cpInUtf8Char);

char* DecToChar(size_t inDec, char* pOutChar = NULL);
WCHAR* DecToWChar(size_t inDec, WCHAR* pOutWChar = NULL);

char* HexToChar(size_t inHex, char* pOutChar = NULL);
WCHAR* HexToWChar(size_t inHex, WCHAR* pOutWChar = NULL);

char* CharToEnvString(const char* cpInChar, char* pOutChar, size_t nInSize = (size_t)-1);
WCHAR* WCharToEnvString(const WCHAR* cpInWChar, WCHAR* pOutWChar, size_t nInSize = (size_t)-1);

size_t CharToDeleteReturnCode(char* pInChar, size_t nSize = (size_t)-1);
size_t WCharToDeleteReturnCode(WCHAR* pInWChar, size_t nSize = (size_t)-1);

char* CharToSpaceSkip(const char* cpInChar);
WCHAR* WCharToSpaceSkip(const WCHAR* cpInWChar);

unsigned char* CharToHex(const char* cpInChar, unsigned char* pOutHex, size_t nInSize);
BYTE* CharToBinary(BYTE* pOutBinary, const char* cpInChar, size_t nInCharSize);

unsigned char* WCharToHex(const WCHAR* cpInWChar, unsigned char* pOutHex, size_t nInSize);
BYTE* WCharToBinary(BYTE* pOutBinary, const WCHAR* cpInWChar, size_t nInWCharSize);

size_t CharToHashFileLine(const char* cpInChar, size_t nInSize, char* pOutFileName, unsigned char* pOutHash, size_t nOutHashSize = 32);
size_t WCharToHashFileLine(const WCHAR* cpInWChar, size_t nInSize, WCHAR* pOutFileName, unsigned char* pOutHash, size_t nOutHashSize = 32);

size_t CharToGetLine(char** ppOutChar, size_t* npInCount, const char* cpInChar, size_t nInCharSize);
size_t WCharToGetLine(WCHAR** ppOutWChar, size_t* npInCount, const WCHAR* cpInWChar, size_t nInCharSize);


size_t CharToFWrite(FILE* fp, const void* cpInChar, size_t nSize);
size_t CharToFWrite(FILE* fp, const char* cpInChar);

size_t CharToCharFWrite(FILE* fp, const char* cpInChar);
size_t CharToWCharFWrite(FILE* fp, const char* cpInChar);
size_t CharToUtf8CharFWrite(FILE* fp, const char* cpInChar);

size_t WCharToCharFWrite(FILE* fp, const WCHAR* cpInWChar);
size_t WCharToFWrite(FILE* fp, const WCHAR* cpInWChar);
size_t WCharToCharFWrite(FILE* fp, const WCHAR* cpInWChar);

size_t Utf8CharToFWrite(FILE* fp, const char* cpInUtf8Char);
size_t Utf8CharToWCharFWrite(FILE* fp, const char* cpInUtf8Char);
size_t Utf8CharToUtf8CharFWrite(FILE* fp, const char* cpUtf8InChar);


BOOL CharToWriteFile(HANDLE hFile, const void* cpInChar, DWORD nLength);

BOOL CharToWriteFile(HANDLE hFile, const char* cpInChar);
BOOL CharToWCharWriteFile(HANDLE hFile, const char* cpInChar);
BOOL CharToUtf8CharWriteFile(HANDLE hFile, const char* cpInChar);

BOOL WCharToCharWriteFile(HANDLE hFile, const WCHAR* cpInWChar);
BOOL WCharToWriteFile(HANDLE hFile, const WCHAR* cpInWChar);
BOOL WCharToUtf8CharWriteFile(HANDLE hFile, const WCHAR* cpInWChar);

BOOL Utf8CharToCharWriteFile(HANDLE hFile, const char* cpInUtf8Char);
BOOL Utf8CharToWCharWriteFile(HANDLE hFile, const char* cpInUtf8Char);
BOOL Utf8CharToWriteFile(HANDLE hFile, const char* cpInUtf8Char);

BOOL GetCharIsBool(const char* cpInChar);
BOOL GetWCharIsBool(const WCHAR* cpInWChar);

char* CharToUpper(char* pInChar);
WCHAR* WCharToUpper(WCHAR* pInWChar);

char* CharToUpper(char* pInChar, size_t nInSize);
WCHAR* WCharToUpper(WCHAR* pInWChar, size_t nInSize);

char* CharToLower(char* pInChar);
WCHAR* WCharToLower(WCHAR* pInWChar);

char* CharToLower(char* pInChar, size_t nInSize);
WCHAR* WCharToLower(WCHAR* pInWChar, size_t nInSize);

char* CharToCopy(const char* cpInChar, const size_t nSize = 101);
WCHAR* WCharToCopy(const WCHAR* cpInWChar, const size_t nSize = 101);

char* CharToCopy(const char* cpInChar, const char* cpCharArg1, const size_t nSize = 101);
WCHAR* WCharToCopy(const WCHAR* cpInWChar, const WCHAR* cpWCharArg1, const size_t nSize = 101);

char* CharToCopy(const char* cpInChar, const char* cpCharArg1, const char* cpCharArg2, const size_t nSize = 101);
WCHAR* WCharToCopy(const WCHAR* cpInWChar, const WCHAR* cpWCharArg1, const WCHAR* cpWCharArg2, const size_t nSize = 101);

char* CharToCopy(const char* cpInChar, const char* cpCharArg1, const char* cpCharArg2, const char* cpCharArg3, const size_t nSize = 101);
WCHAR* WCharToCopy(const WCHAR* cpInWChar, const WCHAR* cpWCharArg1, const WCHAR* cpWCharArg2, const WCHAR* cpWCharArg3, const size_t nSize = 101);

char* CharToCopy(const char* cpInChar, const char* cpCharArg1, const char* cpCharArg2, const char* cpCharArg3, const char* cpCharArg4, const size_t nSize = 101);
WCHAR* WCharToCopy(const WCHAR* cpInWChar, const WCHAR* cpWCharArg1, const WCHAR* cpWCharArg2, const WCHAR* cpWCharArg3, const WCHAR* cpWCharArg4, const size_t nSize = 101);

char* CharToCopy(const char* cpInChar, const char* cpCharArg1, const char* cpCharArg2, const char* cpCharArg3, const char* cpCharArg4, const char* cpCharArg5, const size_t nSize = 101);
WCHAR* WCharToCopy(const WCHAR* cpInWChar, const WCHAR* cpWCharArg1, const WCHAR* cpWCharArg2, const WCHAR* cpWCharArg3, const WCHAR* cpWCharArg4, const WCHAR* cpWCharArg5, const size_t nSize = 101);

char* GetCharToRoot(char* pInFileName);
WCHAR* GetWCharToRoot(WCHAR* pInFileName);

char* GetCharToFileName(const char* cpInFileName);
WCHAR* GetWCharToFileName(const WCHAR* cpInFileName);

char* GetCharToExtension(const char* cpInFileName, BOOL bIsNoExtensionReturnNullptr = FALSE);
WCHAR* GetWCharToExtension(const WCHAR* cpInFileName, BOOL bIsNoExtensionReturnNullptr = FALSE);

char* GetCharToFolderName(char* pInFileName);
WCHAR* GetWCharToFolderName(WCHAR* pInFileName);

char* GetUtf8CharToRoot(char* pInFileName);
char* GetUtf8CharToFileName(const char* cpInFileName);
char* GetUtf8CharToExtension(const char* cpInFileName, BOOL bIsNoExtensionReturnNullptr = FALSE);
char* GetUtf8CharToFolderName(char* cpInFileName);

char* GetSystemDirectoryFileNameToCharA(const char* cpFileName);
char* GetSystemDirectoryFileNameToCharW(const WCHAR* cpFileName);

WCHAR* GetSystemDirectoryFileNameToWCharA(const char* cpFileName);
WCHAR* GetSystemDirectoryFileNameToWCharW(const WCHAR* cpFileName);

char* CharFileToCharA(const char* cpInFileName);
char* CharFileToCharW(const WCHAR* cpInFileName);

WCHAR* CharFileToWCharA(const char* cpInFileName);
WCHAR* CharFileToWCharW(const WCHAR* cpInFileName);

char* WCharFileToCharA(const char* cpInFileName);
char* WCharFileToCharW(const WCHAR* cpInFileName);

WCHAR* WCharFileToWCharA(const char* cpInFileName);
WCHAR* WCharFileToWCharW(const WCHAR* cpInFileName);

char* Utf8CharFileToCharA(const char* cpInFileName);
char* Utf8CharFileToCharW(const WCHAR* cpInFileName);

WCHAR* Utf8CharFileToWCharA(const char* cpInFileName);
WCHAR* Utf8CharFileToWCharW(const WCHAR* cpInFileName);

size_t CharToRtfEncodeCharLength(const char* cpInChar);
char* CharToRtfEncodeChar(const char* cpInChar, char* pOutChar = NULL);

char* SetCharToHexChar(const char cpInChar, char* outBuf);
WCHAR* SetCharToHexWChar(const char cpInChar, WCHAR* outBuf);

char* SetCharToHexLowerChar(const char cpInChar, char* outBuf);
WCHAR* SetCharToHexLowerWChar(const char cpInChar, WCHAR* outBuf);

char* BinaryToByteChar(char* pOutChar, const BYTE* cpInBinary, BOOL bIsUpper);
WCHAR* BinaryToByteWChar(WCHAR* pOutWChar, const BYTE* cpInBinary, BOOL bIsUpper);

char* BinaryTo2ByteChar(char* pOutChar, const BYTE* cpInBinary, BOOL bIsUpper);
WCHAR* BinaryTo2ByteWChar(WCHAR* pOutWChar, const BYTE* cpInBinary, BOOL bIsUpper);

char* BinaryTo4ByteChar(char* pOutChar, const BYTE* cpInBinary, BOOL bIsUpper);
WCHAR* BinaryTo4ByteWChar(WCHAR* pOutWChar, const BYTE* cpInBinary, BOOL bIsUpper);

char* BinaryTo8ByteChar(char* pOutChar, const BYTE* cpInBinary, BOOL bIsUpper);
WCHAR* BinaryTo8ByteWChar(WCHAR* pOutWChar, const BYTE* cpInBinary, BOOL bIsUpper);

char* BinaryTo12ByteChar(char* pOutChar, const BYTE* cpInBinary, BOOL bIsUpper);
WCHAR* BinaryTo12ByteWChar(WCHAR* pOutWChar, const BYTE* cpInBinary, BOOL bIsUpper);

char* BinaryTo16ByteChar(char* pOutChar, const BYTE* cpInBinary, BOOL bIsUpper);
WCHAR* BinaryTo16ByteWChar(WCHAR* pOutWChar, const BYTE* cpInBinary, BOOL bIsUpper);

char* BinaryTo20ByteChar(char* pOutChar, const BYTE* cpInBinary, BOOL bIsUpper);
WCHAR* BinaryTo20ByteWChar(WCHAR* pOutWChar, const BYTE* cpInBinary, BOOL bIsUpper);

char* BinaryTo24ByteChar(char* pOutChar, const BYTE* cpInBinary, BOOL bIsUpper);
WCHAR* BinaryTo24ByteWChar(WCHAR* pOutWChar, const BYTE* cpInBinary, BOOL bIsUpper);

char* BinaryTo28ByteChar(char* pOutChar, const BYTE* cpInBinary, BOOL bIsUpper);
WCHAR* BinaryTo28ByteWChar(WCHAR* pOutWChar, const BYTE* cpInBinary, BOOL bIsUpper);

char* BinaryTo32ByteChar(char* pOutChar, const BYTE* cpInBinary, BOOL bIsUpper);
WCHAR* BinaryTo32ByteWChar(WCHAR* pOutWChar, const BYTE* cpInBinary, BOOL bIsUpper);

char* BinaryTo36ByteChar(char* pOutChar, const BYTE* cpInBinary, BOOL bIsUpper);
WCHAR* BinaryTo36ByteWChar(WCHAR* pOutWChar, const BYTE* cpInBinary, BOOL bIsUpper);

char* BinaryTo40ByteChar(char* pOutChar, const BYTE* cpInBinary, BOOL bIsUpper);
WCHAR* BinaryTo40ByteWChar(WCHAR* pOutWChar, const BYTE* cpInBinary, BOOL bIsUpper);

char* BinaryTo44ByteChar(char* pOutChar, const BYTE* cpInBinary, BOOL bIsUpper);
WCHAR* BinaryTo44ByteWChar(WCHAR* pOutWChar, const BYTE* cpInBinary, BOOL bIsUpper);

char* BinaryTo48ByteChar(char* pOutChar, const BYTE* cpInBinary, BOOL bIsUpper);
WCHAR* BinaryTo48ByteWChar(WCHAR* pOutWChar, const BYTE* cpInBinary, BOOL bIsUpper);

char* BinaryTo52ByteChar(char* pOutChar, const BYTE* cpInBinary, BOOL bIsUpper);
WCHAR* BinaryTo52ByteWChar(WCHAR* pOutWChar, const BYTE* cpInBinary, BOOL bIsUpper);

char* BinaryTo56ByteChar(char* pOutChar, const BYTE* cpInBinary, BOOL bIsUpper);
WCHAR* BinaryTo56ByteWChar(WCHAR* pOutWChar, const BYTE* cpInBinary, BOOL bIsUpper);

char* BinaryTo60ByteChar(char* pOutChar, const BYTE* cpInBinary, BOOL bIsUpper);
WCHAR* BinaryTo60ByteWChar(WCHAR* pOutWChar, const BYTE* cpInBinary, BOOL bIsUpper);

char* BinaryTo64ByteChar(char* pOutChar, const BYTE* cpInBinary, BOOL bIsUpper);
WCHAR* BinaryTo64ByteWChar(WCHAR* pOutWChar, const BYTE* cpInBinary, BOOL bIsUpper);

char* BinaryToChar(char* pOutChar, const BYTE* cpBinary, const DWORD dwLength, BOOL bIsUpper = FALSE);
WCHAR* BinaryToWChar(WCHAR* pWChar, const BYTE* cpBinary, const DWORD dwLength, BOOL bIsUpper = FALSE);

char* AlignedBinaryToChar(char* pOutChar, const BYTE* cpAlignedInBinary, const DWORD dwLength, BOOL bIsUpper = FALSE);
WCHAR* AlignedBinaryToWChar(WCHAR* pOutWChar, const BYTE* cpAlignedInBinary, const DWORD dwLength, BOOL bIsUpper = FALSE);

char* FileToCharA(const char* cpInFileName, unsigned __int64* outFilesize);
char* FileToCharW(const WCHAR* cpInFileName, unsigned __int64* outFilesize);

WCHAR* RemoveUnicodeChar(const WCHAR* cpInWChar);

void CharToFree(char* pInChar);
void WCharToFree(WCHAR* pInWChar);

#ifndef Utf8CharToFree
#define Utf8CharToFree CharToFree
#endif

#ifndef MBS_LOWWORD
#define MBS_LOWWORD(c) (char)(((c) >> 8) & 0xFF)
#endif

#ifndef MBS_HIWORD
#define MBS_HIWORD(c) (char)((c) & 0xFF)
#endif

#ifndef INT_CEIL
#define INT_CEIL(a, b) (((a) + (b) - 1) / b)
#endif

#ifndef Is_Kanji1st
#define Is_Kanji1st(c) ((unsigned int)(((unsigned char)(c)) ^ 0x20) - 0xA1 < 0x3C)
#endif

#ifndef IsSjisLeadByteX
#define IsSjisLeadByteX(c) ((((unsigned char)(c) ^ 0x20U) - 0xA1U) < (unsigned char)(120 / 2))
#endif

#ifndef IsSjisTrailByte
#define IsSjisTrailByte(c) ((((unsigned char)(c) - 0x40U) < (unsigned char)(94 * 2 + 1)) && ((unsigned char)(c) != 0x7FU))
#endif

// UTF-8/CESU-8 �P�����̍ő�o�C�g��
#define UTF8_RFC3629_MAXBYTES 4
#define UTF8_RFC2279_MAXBYTES 6
#define UTF8_MAXBYTES UTF8_RFC3629_MAXBYTES
#define CESU8_MAXBYTES 6

#define UTF8_BITS(n) (((n) == 1) ? 7 : (n) * 5 + 1)

#define IS_UTF8_1(n) ((n) <= 0x7FU)
#define IS_UTF8_2(n) (((n) & 0xE0U) == 0xC0U)
#define IS_UTF8_3(n) (((n) & 0xF0U) == 0xE0U)
#define IS_UTF8_4(n) (((n) & 0xF8U) == 0xF0U)
#define IS_UTF8_5(n) (((n) & 0xFCU) == 0xF8U) // RFC2279 �̂�
#define IS_UTF8_6(n) (((n) & 0xFEU) == 0xFCU) // RFC2279 �̂�

#define IS_UTF8_TAIL(n) (((n) & 0xC0U) == 0x80U)

#ifndef BSwap16
#if _MSC_VER > 1300
#define BSwap16(i) (_byteswap_ushort((i)))
#define BSwap32(i) (_byteswap_ulong((i)))
#define BSwap64(i) (_byteswap_uint64((i)))
#else
#define BSwap16(i) ((unsigned short)((((i) >> 8) & 0xff) | (((i) & 0xff) << 8)))
#define BSwap32(i) ((((i) & 0xff000000) >> 24) | (((i) & 0x00ff0000) >> 8) | (((i) & 0x0000ff00) << 8) | (((i) & 0x000000ff) << 24))
#define BSwap64(i) ((((i) & 0xff00000000000000) >> 56)     \
          | (((i) & 0x00ff000000000000) >> 40)   \
          | (((i) & 0x0000ff0000000000) >> 24)   \
          | (((i) & 0x000000ff00000000) >> 8)    \
          | (((i) & 0x00000000ff000000) << 8)    \
          | (((i) & 0x0000000000ff0000) << 24)   \
          | (((i) & 0x000000000000ff00) << 40)   \
          | (((i) & 0x00000000000000ff) << 56))
/*
unsigned long __fastcall BSwap32(unsigned long i);
unsigned __int64 __fastcall BSwap64(unsigned __int64 i);
*/
#endif
#endif

#define MIN_DIGEST_LINE_LENGTH \
  (DIGEST_HEX_BYTES /* length of hexadecimal message digest */ \
   + 2 /* blank and binary indicator */ \
   + 1 /* minimum filename length */ )
#define ISWHITE(c) ((c) == ' ' || (c) == '\t')
/* Split the checksum string S (of length S_LEN) from a BSD 'md5' or
   'sha1' command into two parts: a hexadecimal digest, and the file
   name.  S is modified.  Return true if successful.  */

bool bsd_split_3(char* s, size_t s_len, unsigned char** hex_digest, char** file_name, bool escaped_filename);
bool bsd_split_3(WCHAR* s, size_t s_len, WCHAR** hex_digest, WCHAR** file_name, bool escaped_filename);
bool split_3(char* s, size_t s_len, unsigned char** hex_digest, int* binary, char** file_name,
	const char* digest_type_string, const size_t min_digest_line_length, const size_t digest_hex_bytes);
bool split_3(WCHAR* s, size_t s_len, WCHAR** hex_digest, int* binary, WCHAR** file_name,
	const WCHAR* digest_type_string, const size_t min_digest_line_length, const size_t digest_hex_bytes);

#ifdef _UNICODE
#define IsUnicode 1
#define TCharToFileSize WCharToFileSize
#define BinaryToFile BinaryToFileW
#define CharToFile CharToFileW
#define CharToCharFile CharToCharFileW
#define CharToWCharFile CharToWCharFileW
#define CharToUtf8CharFile CharToUtf8CharFileW
#define WCharToCharFile WCharToCharFileW
#define WCharToWCharFile WCharToWCharFileW
#define WCharToUtf8CharFile WCharToUtf8CharFileW

#define CharToTCharFile CharToWCharFileW
#define WCharToTCharFile WCharToWCharFileW

#define GetTCharToRoot GetWCharToRoot
#define GetTCharToFileName GetWCharToFileName
#define GetTCharToExtension GetWCharToExtension
#define GetTCharToFolderName GetWCharToFolderName
#define GetSystemDirectoryFileNameToTChar GetSystemDirectoryFileNameToWChar
#define GetSystemDirectoryFileNameToChar GetSystemDirectoryFileNameToCharW
#define GetSystemDirectoryFileNameToWChar GetSystemDirectoryFileNameToWCharW

#define CharFileToChar CharFileToCharW
#define CharFileToWChar CharFileToWCharW
#define WCharFileToChar WCharFileToCharW
#define WCharFileToWChar WCharFileToWCharW
#define Utf8CharFileToChar Utf8CharFileToCharW
#define Utf8CharFileToWChar Utf8CharFileToWCharW

#define TCharToCharConv WCharToCharConv
#define TCharToCharLength WCharToCharLength
#define TCharToWCharConv WCharToWCharConv
#define TCharToWCharLength WCharToWCharLength
#define TCharToUtf8CharConv WCharToUtf8CharConv
#define TCharToUtf8CharLength WCharToUtf8CharLength
#define CharToTCharConv CharToWCharConv
#define CharToTCharLength CharToWCharLength
#define WCharToTCharConv WCharToWCharConv
#define WCharToTCharLength WCharToWCharLength
#define Utf8CharToTCharConv Utf8CharToWCharConv
#define Utf8CharToTCharLength Utf8CharToWCharLength
#define TCharToEnvString WCharToEnvString
#define TCharToDeleteReturnCode WCharToDeleteReturnCode
#define qtcslen wcslen
#define TCharToUpper WCharToUpper
#define TCharToLower WCharToLower
#define TCharToCopy WCharToCopy
#define CharToBase64ToTChar CharToBase64ToWChar
#define BinaryToBase64ToTChar BinaryToBase64ToWChar
#define SetCharToHexTChar SetCharToHexWChar
#define SetCharToHexLowerTChar SetCharToHexLowerWChar
#define BinaryToTChar BinaryToWChar
#define AlignedBinaryToTChar AlignedBinaryToWChar

#define TCharToFWrite WCharToFWrite
#define TCharToCharFWrite WCharToCharFWrite
#define TCharToWCharFWrite WCharToWCharFWrite
#define TCharToUtf8CharFWrite WCharToWCharFWrite

#define TCharToWriteFile WCharToWriteFile
#define TCharToCharWriteFile WCharToCharWriteFile
#define TCharToWCharWriteFile WCharToWriteFile
#define TCharToUtf8CharWriteFile WCharToUtf8CharWriteFile
#define TCharToTCharFile WCharToWCharFileW
#define TCharToCharFile WCharToCharFileW
#define TCharToWCharFile WCharToWCharFileW
#define TCharToUtf8CharFile WCharToUtf8CharFileW
#define GetTCharIsBool GetWCharIsBool
#define TCharToHashFileLine WCharToHashFileLine
#define DecToTChar DecToWChar
#define IntToTChar DecToWChar
#define FileToChar FileToCharW
#else
#define IsUnicode 0
#define TCharToFileSize CharToFileSize
#define BinaryToFile BinaryToFileA
#define CharToFile CharToFileA
#define CharToCharFile CharToCharFileA
#define CharToWCharFile CharToWCharFileA
#define CharToUtf8CharFile CharToUtf8CharFileA
#define WCharToCharFile WCharToCharFileA
#define WCharToWCharFile WCharToWCharFileA
#define WCharToUtf8CharFile WCharToUtf8CharFileA

#define CharToTCharFile CharToCharFileA
#define WCharToTCharFile WCharToCharFileA

#define GetTCharToRoot GetCharToRoot
#define GetTCharToFileName GetCharToFileName
#define GetTCharToExtension GetCharToExtension
#define GetTCharToFolderName GetCharToFolderName
#define GetSystemDirectoryFileNameToTChar GetSystemDirectoryFileNameToChar
#define GetSystemDirectoryFileNameToChar GetSystemDirectoryFileNameToCharA
#define GetSystemDirectoryFileNameToWChar GetSystemDirectoryFileNameToWCharA

#define CharFileToChar CharFileToCharA
#define CharFileToWChar CharFileToWCharA
#define WCharFileToChar WCharFileToCharA
#define WCharFileToWChar WCharFileToWCharA
#define Utf8CharFileToChar Utf8CharFileToCharA
#define Utf8CharFileToWChar Utf8CharFileToWCharA

#define TCharToCharConv CharToCharConv
#define TCharToCharLength CharToCharLength
#define TCharToWCharConv CharToWCharConv
#define TCharToWCharLength CharToWCharLength
#define TCharToUtf8CharConv CharToUtf8CharConv
#define TCharToUtf8CharLength CharToUtf8CharLength
#define CharToTCharConv CharToCharConv
#define CharToTCharLength CharToCharLength
#define WCharToTCharConv WCharToCharConv
#define WCharToTCharLength WCharToCharLength
#define Utf8CharToTCharConv Utf8CharToCharConv
#define Utf8CharToTCharLength Utf8CharToCharLength
#define TCharToEnvString CharToEnvString
#define TCharToDeleteReturnCode CharToDeleteReturnCode
#define qtcslen qmbslen
#define TCharToUpper CharToUpper
#define TCharToLower CharToLower
#define TCharToCopy CharToCopy
#define CharToBase64ToTChar CharToBase64
#define BinaryToBase64ToTChar BinaryToBase64
#define SetCharToHexTChar SetCharToHexChar
#define SetCharToHexLowerTChar SetCharToHexLowerChar
#define BinaryToTChar BinaryToChar
#define AlignedBinaryToTChar AlignedBinaryToChar

#define TCharToFWrite CharToFWrite
#define TCharToCharFWrite CharToCharFWrite
#define TCharToWCharFWrite CharToWCharFWrite
#define TCharToUtf8CharFWrite CharToWCharFWrite

#define TCharToWriteFile CharToWriteFile
#define TCharToCharWriteFile CharToWriteFile
#define TCharToWCharWriteFile CharToWCharWriteFile
#define TCharToUtf8CharWriteFile CharToUtf8CharWriteFile
#define TCharToTCharFile CharToCharFileA
#define TCharToCharFile CharToCharFileA
#define TCharToWCharFile CharToWCharFileA
#define TCharToUtf8CharFile CharToUtf8CharFileA
#define GetTCharIsBool GetCharIsBool
#define TCharToHashFileLine CharToHashFileLine
#define DecToTChar DecToChar
#define IntToTChar DecToChar
#define FileToChar FileToCharA
#endif

//#define _BYTE1(x) ((x) & 0xFF)
//#define _BYTE2(x) (((x) >>  8) & 0xFF)
//#define _BYTE3(x) (((x) >> 16) & 0xFF)
//#define _BYTE4(x) (((x) >> 24) & 0xFF)

//#define BYTE_SWAP_16(x) ((uint16_t)(_BYTE1(x) << 8 | _BYTE2(x)))
//#define BYTE_SWAP_32(x) ((uint32_t)(_BYTE1(x) << 24 | _BYTE2(x) << 16 | _BYTE3(x) << 8 | _BYTE4(x)))

#ifndef TOO_SMALL
#define TOO_SMALL(LEN) ((LEN) < sizeof(size_t))
#endif
#ifndef UNALIGNED1
#define UNALIGNED1(X) ((size_t)(X) & (sizeof(size_t) - 1))
#endif
#ifndef UNALIGNED2
#define UNALIGNED2(X, Y) (((size_t)(X) & (sizeof(size_t) - 1)) | ((size_t)(Y) & (sizeof(size_t) - 1)))
#endif

#ifndef DETECTNULL
#if SIZE_MAX == 0xffffffffui32
#define DETECTNULL(X) (((X) - 0x01010101) & ~(X) & 0x80808080)
#else
#if SIZE_MAX == 0xffffffffffffffffui64
/* Nonzero if X (a long int) contains a NULL byte. */
#define DETECTNULL(X) (((X) - 0x0101010101010101) & ~(X) & 0x8080808080808080)
#else
#error long int is not a 32bit or 64bit type.
#endif
#endif
#endif


#define CHAR_TO_ZENKAKU_1BYTE(char1) ((char1) >> 8 & 0xFF)
#define CHAR_TO_ZENKAKU_2BYTE(char1) ((char1) & 0xFF)

#define CHAR_TO_2CHAR_TYPE unsigned short
#define CHAR_TO_4CHAR_TYPE unsigned int
#define CHAR_TO_8CHAR_TYPE unsigned __int64

#define MAKE_CHAR_TO_INT_1CHAR(char1) (char1)
#define MAKE_CHAR_TO_INT_2CHAR(char1, char2) (((CHAR_TO_2CHAR_TYPE)(char2) << 8) + (CHAR_TO_2CHAR_TYPE)(char1))
#define MAKE_CHAR_TO_INT_3CHAR(char1, char2, char3) (((CHAR_TO_4CHAR_TYPE)(char3) << 16) + ((CHAR_TO_4CHAR_TYPE)(char2) << 8) + (CHAR_TO_4CHAR_TYPE)(char1))
#define MAKE_CHAR_TO_INT_4CHAR(char1, char2, char3, char4) (((CHAR_TO_4CHAR_TYPE)(char4) << 24) + ((CHAR_TO_4CHAR_TYPE)(char3) << 16) + ((CHAR_TO_4CHAR_TYPE)(char2) << 8) + (CHAR_TO_4CHAR_TYPE)(char1))

#define MAKE_CHAR_TO_INT_5CHAR(char1, char2, char3, char4, char5) (((CHAR_TO_8CHAR_TYPE)(char5) << 32) + (MAKE_CHAR_TO_INT_4CHAR(char1, char2, char3, char4)))
#define MAKE_CHAR_TO_INT_6CHAR(char1, char2, char3, char4, char5, char6) (((CHAR_TO_8CHAR_TYPE)MAKE_CHAR_TO_INT_2CHAR(char5, char6) << 32) + MAKE_CHAR_TO_INT_4CHAR(char1, char2, char3, char4))
#define MAKE_CHAR_TO_INT_7CHAR(char1, char2, char3, char4, char5, char6, char7) (((CHAR_TO_8CHAR_TYPE)MAKE_CHAR_TO_INT_3CHAR(char5, char6, char7) << 32) + MAKE_CHAR_TO_INT_4CHAR(char1, char2, char3, char4))
#define MAKE_CHAR_TO_INT_8CHAR(char1, char2, char3, char4, char5, char6, char7, char8) ((((CHAR_TO_8CHAR_TYPE)MAKE_CHAR_TO_INT_4CHAR(char5, char6, char7, char8)) << 32) + MAKE_CHAR_TO_INT_4CHAR(char1, char2, char3, char4))

#define CHAR_COMP_TO_INT_1CHAR(string, char1) (*(string) == (char1))
#define CHAR_COMP_TO_INT_2CHAR(string, char1, char2) (*(CHAR_TO_2CHAR_TYPE*)(string) == MAKE_CHAR_TO_INT_2CHAR((char1), (char2)))
#define CHAR_COMP_TO_INT_3CHAR(string, char1, char2, char3) ((*(CHAR_TO_4CHAR_TYPE*)(string) & 0x00FFFFFF) == MAKE_CHAR_TO_INT_3CHAR((char1), (char2), (char3)))
#define CHAR_COMP_TO_INT_4CHAR(string, char1, char2, char3, char4) (*(CHAR_TO_4CHAR_TYPE*)(string) == MAKE_CHAR_TO_INT_4CHAR((char1), (char2), (char3), (char4)))
#define CHAR_COMP_TO_INT_5CHAR(string, char1, char2, char3, char4, char5) ((*(CHAR_TO_8CHAR_TYPE*)(string) & 0x000000FFFFFFFFFF) == MAKE_CHAR_TO_INT_5CHAR((char1), (char2), (char3), (char4), (char5)))
#define CHAR_COMP_TO_INT_6CHAR(string, char1, char2, char3, char4, char5, char6) ((*(CHAR_TO_8CHAR_TYPE*)(string) & 0x0000FFFFFFFFFFFF) == MAKE_CHAR_TO_INT_6CHAR((char1), (char2), (char3), (char4), (char5), (char6)))
#define CHAR_COMP_TO_INT_7CHAR(string, char1, char2, char3, char4, char5, char6, char7) ((*(CHAR_TO_8CHAR_TYPE*)(string) & 0x00FFFFFFFFFFFFFF) == MAKE_CHAR_TO_INT_7CHAR((char1), (char2), (char3), (char4), (char5), (char6), (char7)))
#define CHAR_COMP_TO_INT_8CHAR(string, char1, char2, char3, char4, char5, char6, char7, char8) (*(CHAR_TO_8CHAR_TYPE*)(string) == MAKE_CHAR_TO_INT_8CHAR((char1), (char2), (char3), (char4), (char5), (char6), (char7), (char8)))

#define CHAR_COPY_TO_INT_1CHAR(string, char1) *(string) = MAKE_CHAR_TO_INT_1CHAR((char1))
#define CHAR_COPY_TO_INT_2CHAR(string, char1, char2) *(CHAR_TO_2CHAR_TYPE*)(string) = MAKE_CHAR_TO_INT_2CHAR((char1), (char2))
#define CHAR_COPY_TO_INT_3CHAR(string, char1, char2, char3) CHAR_COPY_TO_INT_2CHAR((string), (char1), (char2)); CHAR_COPY_TO_INT_1CHAR(((string) + 2), (char3))
#define CHAR_COPY_TO_INT_4CHAR(string, char1, char2, char3, char4) *(CHAR_TO_4CHAR_TYPE*)(string) = MAKE_CHAR_TO_INT_4CHAR((char1), (char2), (char3), (char4))
#define CHAR_COPY_TO_INT_5CHAR(string, char1, char2, char3, char4, char5) CHAR_COPY_TO_INT_4CHAR((string), (char1), (char2), (char3), (char4)); CHAR_COPY_TO_INT_1CHAR(((string) + 4), (char5))
#define CHAR_COPY_TO_INT_6CHAR(string, char1, char2, char3, char4, char5, char6) CHAR_COPY_TO_INT_4CHAR((string), (char1), (char2), (char3), (char4)); CHAR_COPY_TO_INT_2CHAR(((string) + 4), (char5), (char6))
#define CHAR_COPY_TO_INT_7CHAR(string, char1, char2, char3, char4, char5, char6, char7) CHAR_COPY_TO_INT_4CHAR((string), (char1), (char2), (char3), (char4)); CHAR_COPY_TO_INT_3CHAR(((string) + 4), (char5), (char6), (char7))
#define CHAR_COPY_TO_INT_8CHAR(string, char1, char2, char3, char4, char5, char6, char7, char8) *(CHAR_TO_8CHAR_TYPE*)(string) = MAKE_CHAR_TO_INT_8CHAR((string), (char1), (char2), (char3), (char4), (char5), (char6), (char7), (char8))

#define CHAR_COPY_TO_1CHAR(string, src) *(string) = *(src)
#define CHAR_COPY_TO_2CHAR(string, src) *(CHAR_TO_2CHAR_TYPE*)(string) = *(CHAR_TO_2CHAR_TYPE*)(src)
#define CHAR_COPY_TO_3CHAR(string, src) *(CHAR_TO_2CHAR_TYPE*)(string) = *(CHAR_TO_2CHAR_TYPE*)(src); *((string) + 2) = *((src) + 2)
#define CHAR_COPY_TO_4CHAR(string, src) *(CHAR_TO_4CHAR_TYPE*)(string) = *(CHAR_TO_4CHAR_TYPE*)(src)
#define CHAR_COPY_TO_5CHAR(string, src) *(CHAR_TO_4CHAR_TYPE*)(string) = *(CHAR_TO_4CHAR_TYPE*)(src); *((string) + 4) = *((src) + 4)
#define CHAR_COPY_TO_6CHAR(string, src) *(CHAR_TO_4CHAR_TYPE*)(string) = *(CHAR_TO_4CHAR_TYPE*)(src); *(CHAR_TO_2CHAR_TYPE*)((string) + 4) = *(CHAR_TO_2CHAR_TYPE*)((src) + 4)
#define CHAR_COPY_TO_7CHAR(string, src) *(CHAR_TO_4CHAR_TYPE*)(string) = *(CHAR_TO_4CHAR_TYPE*)(src); *(CHAR_TO_2CHAR_TYPE*)((string) + 4) = *(CHAR_TO_2CHAR_TYPE*)((src) + 4); *((string) + 6) = *((src) + 6)
#define CHAR_COPY_TO_8CHAR(string, src) *(CHAR_TO_8CHAR_TYPE*)(string) = *(CHAR_TO_8CHAR_TYPE*)(src)

#define CHAR_COMP_TO_1CHAR(string, char1) (*(string) == (char1))
#define CHAR_COMP_TO_2CHAR(string, char1, char2) ((*((string) + 0) == (char1)) && (*((string) + 1) == (char2)))
#define CHAR_COMP_TO_3CHAR(string, char1, char2, char3) ((*((string) + 0) == (char1)) && (*((string) + 1) == (char2)) && (*((string) + 2) == (char3)))
#define CHAR_COMP_TO_4CHAR(string, char1, char2, char3, char4) ((*((string) + 0) == (char1)) && (*((string) + 1) == (char2)) && (*((string) + 2) == (char3)) && (*((string) + 3) == (char4)))


#define WCHAR_TO_2CHAR_TYPE unsigned long
#define WCHAR_TO_4CHAR_TYPE unsigned __int64

#define MAKE_WCHAR_TO_INT_1CHAR(char1) (char1)
#define MAKE_WCHAR_TO_INT_2CHAR(char1, char2) ((WCHAR_TO_2CHAR_TYPE)(char2) << 16) + (WCHAR_TO_2CHAR_TYPE)(char1) 
#define MAKE_WCHAR_TO_INT_3CHAR(char1, char2, char3) ((WCHAR_TO_4CHAR_TYPE)(char3) << 32) + ((WCHAR_TO_2CHAR_TYPE)(char2) << 16) + (WCHAR_TO_2CHAR_TYPE)(char1)
#define MAKE_WCHAR_TO_INT_4CHAR(char1, char2, char3, char4) ((WCHAR_TO_4CHAR_TYPE)(char4) << 48) + ((WCHAR_TO_4CHAR_TYPE)(char3) << 32) + ((WCHAR_TO_2CHAR_TYPE)(char2) << 16) + (WCHAR_TO_2CHAR_TYPE)(char1)

#define WCHAR_COMP_TO_INT_1CHAR(string, char1) (*(string) == MAKE_WCHAR_TO_INT_1CHAR(char1))
#define WCHAR_COMP_TO_INT_2CHAR(string, char1, char2) (*(WCHAR_TO_2CHAR_TYPE*)(string) == MAKE_WCHAR_TO_INT_2CHAR((char1), (char2)))
#define WCHAR_COMP_TO_INT_3CHAR(string, char1, char2, char3) ((*(WCHAR_TO_4CHAR_TYPE*)(string) & 0x0000FFFFFFFFFFFF) == MAKE_WCHAR_TO_INT_3CHAR((char1), (char2), (char3)))
#define WCHAR_COMP_TO_INT_4CHAR(string, char1, char2, char3, char4) (*(WCHAR_TO_4CHAR_TYPE*)(string) == MAKE_WCHAR_TO_INT_4CHAR((char1), (char2), (char3), (char4)))

#define WCHAR_COPY_TO_INT_1CHAR(string, char1) *(string) = MAKE_WCHAR_TO_INT_1CHAR(char1)
#define WCHAR_COPY_TO_INT_2CHAR(string, char1, char2) *(WCHAR_TO_2CHAR_TYPE*)(string) = MAKE_WCHAR_TO_INT_2CHAR((char1), (char2))
#define WCHAR_COPY_TO_INT_3CHAR(string, char1, char2, char3) WCHAR_COPY_TO_INT_2CHAR((string), (char1), (char2)); WCHAR_COPY_TO_INT_1CHAR(((string) + 2), (char3))
#define WCHAR_COPY_TO_INT_4CHAR(string, char1, char2, char3, char4) *(WCHAR_TO_4CHAR_TYPE*)(string) = MAKE_WCHAR_TO_INT_4CHAR((char1), (char2), (char3), (char4))

#define WCHAR_COPY_TO_1CHAR(string, src) *(string) = *(src)
#define WCHAR_COPY_TO_2CHAR(string, src) *(WCHAR_TO_2CHAR_TYPE*)(string) = *(WCHAR_TO_2CHAR_TYPE*)(src)
#define WCHAR_COPY_TO_3CHAR(string, src) *(WCHAR_TO_2CHAR_TYPE*)(string) = *(WCHAR_TO_2CHAR_TYPE*)(src); *((string) + 2) = *((src) + 2)
#define WCHAR_COPY_TO_4CHAR(string, src) *(WCHAR_TO_4CHAR_TYPE*)(string) = *(WCHAR_TO_4CHAR_TYPE*)(src)
#define WCHAR_COPY_TO_5CHAR(string, src) *(WCHAR_TO_4CHAR_TYPE*)(string) = *(WCHAR_TO_4CHAR_TYPE*)(src); *((string) + 4) = *((src) + 4)
#define WCHAR_COPY_TO_6CHAR(string, src) *(WCHAR_TO_4CHAR_TYPE*)(string) = *(WCHAR_TO_4CHAR_TYPE*)(src); *(WCHAR_TO_2CHAR_TYPE*)((string) + 4) = *(WCHAR_TO_2CHAR_TYPE*)((src) + 4)
#define WCHAR_COPY_TO_7CHAR(string, src) *(WCHAR_TO_4CHAR_TYPE*)(string) = *(WCHAR_TO_4CHAR_TYPE*)(src); *(WCHAR_TO_2CHAR_TYPE*)((string) + 4) = *(WCHAR_TO_2CHAR_TYPE*)((src) + 4); *((string) + 6) = *((src) + 6)
#define WCHAR_COPY_TO_8CHAR(string, src) *(WCHAR_TO_4CHAR_TYPE*)(string) = *(WCHAR_TO_4CHAR_TYPE*)(src); *(WCHAR_TO_4CHAR_TYPE*)((string) + 4) = *(WCHAR_TO_4CHAR_TYPE*)((src) + 4)

#define WCHAR_COMP_TO_1CHAR(string, char1) (*(string) == (char1))
#define WCHAR_COMP_TO_2CHAR(string, char1, char2) ((*((string) + 0) == (char1)) && (*((string) + 1) == (char2)))
#define WCHAR_COMP_TO_3CHAR(string, char1, char2, char3) ((*((string) + 0) == (char1)) && (*((string) + 1) == (char2)) && (*((string) + 2) == (char3)))
#define WCHAR_COMP_TO_4CHAR(string, char1, char2, char3, char4) ((*((string) + 0) == (char1)) && (*((string) + 1) == (char2)) && (*((string) + 2) == (char3)) && (*((string) + 3) == (char4)))

#define TCHAR_COMP_TO_1CHAR(string, char1) CHAR_COMP_TO_1CHAR(string, char1)
#define TCHAR_COMP_TO_2CHAR(string, char1, char2) CHAR_COMP_TO_2CHAR(string, char1, char2)
#define TCHAR_COMP_TO_3CHAR(string, char1, char2, char3) CHAR_COMP_TO_3CHAR(string, char1, char2, char3)
#define TCHAR_COMP_TO_4CHAR(string, char1, char2, char3, char4) CHAR_COMP_TO_4CHAR(string, char1, char2, char3, char4)

#ifdef _UNICODE

#define TCHAR_TO_2CHAR_TYPE WCHAR_TO_2CHAR_TYPE
#define TCHAR_TO_4CHAR_TYPE WCHAR_TO_4CHAR_TYPE

#define MAKE_TCHAR_TO_INT_2CHAR(char1, char2) MAKE_WCHAR_TO_INT_2CHAR(char1, char2)
#define MAKE_TCHAR_TO_INT_3CHAR(char1, char2, char3) MAKE_WCHAR_TO_INT_3CHAR(char1, char2, char3)
#define MAKE_TCHAR_TO_INT_4CHAR(char1, char2, char3, char4) MAKE_WCHAR_TO_INT_4CHAR(char1, char2, char3, char4)

#define TCHAR_COMP_TO_INT_1CHAR(string, char1) WCHAR_COMP_TO_INT_1CHAR(string, char1)
#define TCHAR_COMP_TO_INT_2CHAR(string, char1, char2) WCHAR_COMP_TO_INT_2CHAR(string, char1, char2)
#define TCHAR_COMP_TO_INT_3CHAR(string, char1, char2, char3) WCHAR_COMP_TO_INT_3CHAR(string, char1, char2, char3)
#define TCHAR_COMP_TO_INT_4CHAR(string, char1, char2, char3, char4) WCHAR_COMP_TO_INT_4CHAR(string, char1, char2, char3, char4)

#define TCHAR_COPY_TO_INT_1CHAR(string, char1) WCHAR_COPY_TO_INT_1CHAR(string, char1)
#define TCHAR_COPY_TO_INT_2CHAR(string, char1, char2) WCHAR_COPY_TO_INT_2CHAR(string, char1, char2)
#define TCHAR_COPY_TO_INT_3CHAR(string, char1, char2, char3) WCHAR_COPY_TO_INT_3CHAR(string, char1, char2, char3)
#define TCHAR_COPY_TO_INT_4CHAR(string, char1, char2, char3, char4) WCHAR_COPY_TO_INT_4CHAR(string, char1, char2, char3, char4)

#else

#define TCHAR_TO_2CHAR_TYPE CHAR_TO_2CHAR_TYPE
#define TCHAR_TO_4CHAR_TYPE CHAR_TO_4CHAR_TYPE

#define MAKE_TCHAR_TO_INT_2CHAR(char1, char2) MAKE_CHAR_TO_INT_2CHAR(char1, char2)
#define MAKE_TCHAR_TO_INT_3CHAR(char1, char2, char3) MAKE_CHAR_TO_INT_3CHAR(char1, char2, char3)
#define MAKE_TCHAR_TO_INT_4CHAR(char1, char2, char3, char4) MAKE_CHAR_TO_INT_4CHAR(char1, char2, char3, char4)

#define TCHAR_COMP_TO_INT_1CHAR(string, char1) CHAR_COMP_TO_INT_1CHAR(string, char1)
#define TCHAR_COMP_TO_INT_2CHAR(string, char1, char2) CHAR_COMP_TO_INT_2CHAR(string, char1, char2)
#define TCHAR_COMP_TO_INT_3CHAR(string, char1, char2, char3) CHAR_COMP_TO_INT_3CHAR(string, char1, char2, char3)
#define TCHAR_COMP_TO_INT_4CHAR(string, char1, char2, char3, char4) CHAR_COMP_TO_INT_4CHAR(string, char1, char2, char3, char4)

#define TCHAR_COPY_TO_INT_1CHAR(string, char1) CHAR_COPY_TO_INT_1CHAR(string, char1)
#define TCHAR_COPY_TO_INT_2CHAR(string, char1, char2) CHAR_COPY_TO_INT_2CHAR(string, char1, char2)
#define TCHAR_COPY_TO_INT_3CHAR(string, char1, char2, char3) CHAR_COPY_TO_INT_3CHAR(string, char1, char2, char3)
#define TCHAR_COPY_TO_INT_4CHAR(string, char1, char2, char3, char4) CHAR_COPY_TO_INT_4CHAR(string, char1, char2, char3, char4)

#endif
#endif