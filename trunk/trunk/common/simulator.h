// -*-	Mode:C++; c-basic-offset:8; tab-width:8; indent-tabs-mode:t -*- 

/*
 * Copyright (C) 2000 by the University of Southern California
 * $Id: simulator.h,v 1.1.1.1 2008/04/11 18:40:30 rouil Exp $
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License,
 * version 2, as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 59 Temple Place, Suite 330, Boston, MA 02111-1307, USA.
 *
 *
 * The copyright of this module includes the following
 * linking-with-specific-other-licenses addition:
 *
 * In addition, as a special exception, the copyright holders of
 * this module give you permission to combine (via static or
 * dynamic linking) this module with free software programs or
 * libraries that are released under the GNU LGPL and with code
 * included in the standard release of ns-2 under the Apache 2.0
 * license or under otherwise-compatible licenses with advertising
 * requirements (or modified versions of such code, with unchanged
 * license).  You may copy and distribute such a system following the
 * terms of the GNU GPL for this module and the licenses of the
 * other code concerned, provided that you include the source code of
 * that other code when and as the GNU GPL requires distribution of
 * source code.
 *
 * Note that people who make modified versions of this module
 * are not obligated to grant this special exception for their
 * modified versions; it is their choice whether to do so.  The GNU
 * General Public License gives permission to release a modified
 * version without this exception; this exception also makes it
 * possible to release a modified version which carries forward this
 * exception.
 *
 */

/*
 * Simulator object that handles population of classifiers 
 */

#ifndef ns_simulator_h
#define ns_simulator_h

#include <tclcl.h>
#include "object.h"

class ParentNode;
class RouteLogic;

class Simulator : public TclObject {
public:
	static Simulator& instance() { return (*instance_); }
      Simulator() : nodelist_(NULL), rtobject_(NULL), nn_(0), \
	size_(0) {}
      ~Simulator() {
	    delete []nodelist_; 
      }
	char* macType() { return macType_; }
	int command(int argc, const char*const* argv);
	void populate_flat_classifiers();
	void populate_hier_classifiers();
	void add_node(ParentNode *node, int id);
	NsObject* get_link_head(ParentNode *node, int nh);
	int node_id_by_addr(int address);
	char *append_addr(int level, int *addr);
	void alloc(int n);
	void check(int n);
	
private:
        ParentNode **nodelist_;
	RouteLogic *rtobject_;
	int nn_;
	int size_;
	char macType_[SMALL_LEN];
	static Simulator* instance_;
};

#endif /* ns_simulator_h */
