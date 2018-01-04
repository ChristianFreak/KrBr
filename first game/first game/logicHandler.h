#ifndef LOGICHANDLER_H
#define LOGICHANDLER_H

#include "camera.h"
#include "renderTarget.h"

class LogicHandler
{
public:
	void PossibleCollision(std::vector<RenderTarget*> targets, Camera& camera);
	inline bool GetForward() { return m_moveF; }
	inline bool GetBackwards() { return m_moveB; }
	inline bool GetRight() { return m_moveR; }
	inline bool GetLeft() { return m_moveL; }
	inline bool GetUp() { return m_moveU; }
	inline bool GetDown() { return m_moveD; }
private:
	bool m_moveF;
	bool m_moveB;
	bool m_moveR;
	bool m_moveL;
	bool m_moveU;
	bool m_moveD;
};

#endif // !LOGICHANDLER_H
