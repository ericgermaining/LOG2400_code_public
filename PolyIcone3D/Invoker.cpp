///////////////////////////////////////////////////////////
//  Invoker.cpp
//  Implementation of the Class Invoker
//  Created on:      08-nov.-2018 21:05:19
//  Original author: p482457
///////////////////////////////////////////////////////////

#include <iostream>

#include "Invoker.h"

namespace PolyIcone3D
{
	std::unique_ptr<Invoker> Invoker::m_instance(nullptr);

	Invoker * Invoker::getInstance(void)
	{
		if (m_instance == nullptr)
			m_instance = std::unique_ptr<Invoker>(new Invoker);
		return m_instance.get();
	}

	void Invoker::execute(CmdPtr & cmd)
	{
		cmd->execute();
		m_cmdDone.push_back(cmd);
	}

	void Invoker::undo()
	{
		std::cerr << "Avant Undo: nombre de commandes faites:" << m_cmdDone.size() <<
			", nombre de commandes defaites:" << m_cmdUndone.size() << std::endl;
		if (!m_cmdDone.empty())
		{
			CmdPtr cmd = m_cmdDone.back();
			cmd->cancel();
			m_cmdDone.pop_back();
			m_cmdUndone.push_back(cmd);
		}
		std::cerr << "Apres Undo: nombre de commandes faites:" << m_cmdDone.size() <<
			", nombre de commandes defaites:" << m_cmdUndone.size() << std::endl;
	}

	void Invoker::redo()
	{
		std::cerr << "Avant Redo: nombre de commandes faites:" << m_cmdDone.size() <<
			", nombre de commandes defaites:" << m_cmdUndone.size() << std::endl;
		if (!m_cmdUndone.empty())
		{
			CmdPtr cmd = m_cmdUndone.back();
			cmd->execute();
			m_cmdUndone.pop_back();
			m_cmdDone.push_back(cmd);
		}
		std::cerr << "Apres Redo: nombre de commandes faites:" << m_cmdDone.size() <<
			", nombre de commandes defaites:" << m_cmdUndone.size() << std::endl;
	}

} // namespace PolyIcone3D