/*
 * Group.h
 *
 *  Created on: Aug 19, 2013
 *      Author: Jenna
 */

#ifndef GROUP_H_
#define GROUP_H_

#include <vector>

using namespace std;

class Entity;

class Group {
public:
	Group();
	virtual ~Group();

	void AddMember( Entity* ent );
	void RemoveMember( Entity* ent );

	void Update( double delta );
	void Draw();

	// getters
	Entity* GetMember( int index ) const;
	int Size() const { return mMembers.size(); }

protected:

private:
	vector<Entity*> mMembers;
};

#endif /* GROUP_H_ */
