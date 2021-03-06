/*
 *      vdr-plugin-vnsi - XBMC server plugin for VDR
 *
 *      Copyright (C) 2010 Alwin Esch (Team XBMC)
 *      Copyright (C) 2010, 2011 Alexander Pipelka
 *
 *      http://www.xbmc.org
 *
 *  This Program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2, or (at your option)
 *  any later version.
 *
 *  This Program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with XBMC; see the file COPYING.  If not, see
 *  <http://www.gnu.org/licenses/>.
 *
 */

#ifndef VNSI_SERVER_H
#define VNSI_SERVER_H

#include <vdr/thread.h>

#include "config.h"
#include "status.h"

class cVNSIClient;

class cVNSIServer : public cThread
{
protected:

  virtual void Action(void);
  void NewClientConnected(int fd);

  int           m_ServerPort;
  int           m_ServerFD;
  cString       m_AllowedHostsFile;
  cVNSIStatus   m_Status;

  static unsigned int m_IdCnt;

public:
  cVNSIServer(int listenPort);
  virtual ~cVNSIServer();
};

#endif // VNSI_SERVER_H
