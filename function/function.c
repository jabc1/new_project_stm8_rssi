#include "function.h"
#include "table.h"
#include <stdlib.h>
/*!
 * @file function.c
 * @brief 主要实现对函数的查表执行便于维护
 * @author jason
 * @date 2018-11-21
 * @version ver1.0
 */

const struct attr_exe_data SysAttrTable[] =
{
    {0x01,test_function},
    {0x02,State_function},
    {0x03,SoftVer_funtion}, 
    {0x61,SoftVer_funtion},
};

u8 GetFunctionNum()
{
    return ( sizeof(SysAttrTable) / sizeof(struct attr_exe_data) );
}

bool Msg_deal(u8 *data,u16 len)
{
    u8 i,count;
    _Cmd *pBuf;
    const struct attr_exe_data * p_attr_exe = SysAttrTable;
    pBuf = (_Cmd *)data;
    count = GetFunctionNum();
    
    for(i=0;i<count;i++)
    {
        if(p_attr_exe->cmd == pBuf->head)
        {
            if(p_attr_exe->exe_attr != NULL)
            {
                p_attr_exe->exe_attr(pBuf->head,pBuf->data,sizeof(pBuf->data)-2);
                return true;
            }
        }
        p_attr_exe++;
    }
    return false;
}

void test_function(u8 cmd,u8 *data,u16 len)
{
    ;
}

void State_function(u8 cmd,u8 *data,u16 len)
{
    ;
}

void SoftVer_funtion(u8 cmd,u8 *data,u16 len)
{
    ;
}





