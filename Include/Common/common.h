#pragma once
/*!
 * \file	common.h
 *
 * \author	BrianYi
 * \date	2017/07/11
 *
 * \brief	此文件为整个项目的公共文件
 */

//-------------------------------
// 标准头文件 区
//-------------------------------
#include <iostream>
#include <intsafe.h>
#include <winsock2.h>
#include <process.h>
#include <string>
#include <functional>
using namespace std;

#ifndef P2_NAMESPACE_BEG
#define P2_NAMESPACE_BEG    namespace p2 {
#endif
#ifndef P2_NAMESPACE_END
#define P2_NAMESPACE_END    };
#endif
#ifndef P2_NAMESPACE_USE
#define P2_NAMESPACE_USE    using namespace p2;
#endif

P2_NAMESPACE_BEG



//-------------------------------
// 宏定义 区
//-------------------------------
constexpr size_t kAssertBuffSize = 512;

#define Assert(condition)    {                              \
                                                                \
        if (!(condition))                                       \
        {                                                       \
            char s[kAssertBuffSize];                            \
            s[kAssertBuffSize -1] = 0;                          \
            _snprintf_s (s,kAssertBuffSize -1, "_Assert: %s, %d",__FILE__, __LINE__ ); \
        }   }

//-------------------------------
// 类型定义 区
//-------------------------------


//-------------------------------
// 枚举 区
//-------------------------------
enum IOType
{
    Blocking = 0,
    NonBlocking = 1
};

//-------------------------------
// 常量 区
//-------------------------------
const UINT32 RECV_BUF_SIZE = 10 * 1024u;
const UINT32 SEND_BUF_SIZE = 10 * 1024u;
const INT32 MAX_CONNECTION_NUM = 32;

//-------------------------------
// 全局 区
//-------------------------------
unsigned int atomic_add(unsigned int *area, int val);
unsigned int atomic_or(unsigned int *area, unsigned int val);
unsigned int atomic_sub(unsigned int *area, int val);

P2_NAMESPACE_END