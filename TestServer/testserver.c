/*
    Generic Game Metaserver Test Server

    Copyright (C) 2000 Dragon Master

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
    Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.

    The author can be reached via e-mail to dragonm@leech.org
*/
#include "wrap.h"
#include "dgclibig.h"

int main(int argc, char **argv)
{
  int                sockfd;
  struct sockaddr_in sa;

  if(argc != 2)
    err_quit("usage: testclient <hostname>");

  memset(&sa, 0, sizeof(sa));
  sa.sin_family = AF_INET;
  sa.sin_port = htons(8453);
  Inet_pton(AF_INET, argv[1], &sa.sin_addr);

  sockfd = Socket(AF_INET, SOCK_DGRAM, 0);

  dg_cli(stdin, sockfd, (SA *)&sa, sizeof(sa));

  exit(0);
}
