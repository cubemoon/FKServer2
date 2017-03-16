// CGAskDetailXinFaList.h
// 
// ȡ��ǰ���ǵļ��ܱ�
// 
//////////////////////////////////////////////////////

#ifndef __CGASKSKILLCLASS_H__
#define __CGASKSKILLCLASS_H__

#include "Type.h"
#include "Packet.h"
#include "PacketFactory.h"

namespace Packets
{
class CGAskSkillClass : public Packet
{
public:
	CGAskSkillClass( ){}
	virtual ~CGAskSkillClass( ){}

	//���ü̳нӿ�
	virtual BOOL			Read( SocketInputStream& iStream ) ;
	virtual BOOL			Write( SocketOutputStream& oStream )const ;
	virtual UINT			Execute( Player* pPlayer ) ;

	virtual PacketID_t		GetPacketID()const { return PACKET_CG_ASKDETAILXINFALIST ; }
	virtual UINT			GetPacketSize()const { return sizeof(ObjID_t) ; }
	
public:
	//ʹ�����ݽӿ�
	ObjID_t					getTargetID(VOID) { return m_ObjID; }
	VOID					setTargetID(ObjID_t idTarget) { m_ObjID = idTarget; }

private:
	//����
	ObjID_t					m_ObjID;	//�Է���ObjID
};


class CGAskDetailXinFaListFactory : public PacketFactory 
{
public:
	Packet*		CreatePacket() { return new CGAskSkillClass() ; }
	PacketID_t	GetPacketID()const { return PACKET_CG_ASKDETAILXINFALIST; }
	UINT		GetPacketMaxSize()const { return sizeof(ObjID_t) ; }
};

class CGAskSkillClassHandler 
{
public:
	static UINT Execute( CGAskSkillClass* pPacket, Player* pPlayer ) ;
};




}

using namespace Packets;



#endif