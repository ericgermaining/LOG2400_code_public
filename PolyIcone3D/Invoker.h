///////////////////////////////////////////////////////////
//  Invoker.h
//  Implementation of the Class Invoker
//  Created on:      08-nov.-2018 21:05:18
//  Original author: p482457
///////////////////////////////////////////////////////////

#if !defined(EA_58D999ED_BB97_4cec_AA75_A5ADB8F6662F__INCLUDED_)
#define EA_58D999ED_BB97_4cec_AA75_A5ADB8F6662F__INCLUDED_

#include "CommandAbs.h"

namespace PolyIcone3D
{
	class Invoker
	{
	public:
		virtual ~Invoker() = default;

		static Invoker* getInstance(void);

		virtual void execute(CmdPtr& cmd);
		virtual void undo();
		virtual void redo();

	protected:
		Invoker() = default;

		static std::unique_ptr<Invoker> m_instance;
		CmdContainer m_cmdDone;
		CmdContainer m_cmdUndone;
	};
}
#endif // !defined(EA_58D999ED_BB97_4cec_AA75_A5ADB8F6662F__INCLUDED_)
