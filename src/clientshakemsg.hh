/*
    Generic Game Metaserver Test Client

    Copyright (C) 2000-2004 Dragon Master

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License version 2 as
    published by the Free Software Foundation.  A copy of this license is
    included in this package.  If there is any discrepancy between this copy
    and the version published by the Free Software Foundation, the included
    version shall apply.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 
    02110-1301 USA

    The author can be reached via e-mail to dragonm@hypercubepc.com
*/
#ifndef CLIENTSHAKEMSG_HH
#define CLIENTSHAKEMSG_HH

#include "netmsg.hh"


//=============================================================================
class ClientShakeMsg : public NetMsg
{
public:
  ClientShakeMsg(int handshake);
  ClientShakeMsg(const unsigned char *message,
		 const unsigned int messageLength);

  int GetHandshake() const;

  void SetHandshake(int);
private:
  virtual void Pack();
  virtual void Unpack();

  int mHandshake;
};

//=============================================================================
inline ClientShakeMsg::ClientShakeMsg(int handshake) : NetMsg(),
						       mHandshake(handshake)
{
  mType = NMT_CLIENTSHAKE;
}
//=============================================================================
inline int ClientShakeMsg::GetHandshake() const
{
  return mHandshake;
}
//=============================================================================
inline void ClientShakeMsg::SetHandshake(int handshake)
{
  mHandshake = handshake;
}


#endif
