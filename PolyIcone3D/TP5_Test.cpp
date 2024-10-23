///////////////////////////////////////////////////////////
//  TP5_Test.cpp
//  Implementation of the Class TP5_Test
//  Created on:      29-oct.-2018 09:22:46
//  Original author: p482457
///////////////////////////////////////////////////////////

#include "TP5_Test.h"

#include "Cube.h"
#include "Cylinder.h"
#include "Sphere.h"

#include "VisitorXMLWriter.h"
#include "VisitorPrimitiveSelector.h"

#include "XMLPrintCmd.h"
#include "SelectPrimitiveCmd.h"
#include "TransformCmd.h"

TP5_Test::TP5_Test()
	: m_icone3D(), m_cylTransformed(Cylinder(Point3D(2.5f,1.5f,0.),2,5),Point3D(0.5f,0.5f,0.5f),3)
{
	Cube     cub1(Point3D(1., 2., 3.), 2., 2., 2.);
	Cube     cub2(Point3D(-1., 2., 4.), 2.5f, 2.1f, 4.);
	Cylinder cyl1(Point3D(3., -1., 1.), 1., 2.);
	Cylinder cyl2(Point3D(3., 1., 2.), 1., 2.);
	Sphere   sph1(Point3D(2., 2., 2.), 2.);
	Sphere   sph2(Point3D(3., -1., 1.), 3.5);

	Icone3DComposite compos1;
	compos1.addChild(cub1);
	compos1.addChild(cyl1);
	compos1.addChild(sph1);

	Icone3DComposite compos2;
	compos2.addChild(sph1);
	compos2.addChild(compos1);
	compos2.addChild(cub1);
	compos2.addChild(cyl2);

	m_icone3D.addChild(cub2);
	m_icone3D.addChild(compos2);
	m_icone3D.addChild(sph2);
	m_icone3D.addChild(compos1);
}

TP5_Test::~TP5_Test()
{
}

TP5_Test::RESULTAT TP5_Test::testComposite()
{
	Icone3DIterator_const itIcone = m_icone3D.cbegin();
	if (itIcone == m_icone3D.cend())
	{
		std::cout << "===== testComposite TEST 1 ECHEC" << std::endl;
		return TP5_Test::RESULTAT::ECHEC;
	}

	std::cout << "===== testComposite TEST 1 SUCCES" << std::endl;

	PrimitiveParams paramsCub2 = itIcone->getParameters();
	if(paramsCub2[2] != 4.)
	{
		std::cout << "===== testComposite TEST 2 ECHEC" << std::endl;
		return TP5_Test::RESULTAT::ECHEC;
	}

	std::cout << "===== testComposite TEST 2 SUCCES" << std::endl;

	++itIcone;
	if (itIcone->cbegin() == itIcone->cend())
	{
		std::cout << "===== testComposite TEST 3 ECHEC" << std::endl;
		return TP5_Test::RESULTAT::ECHEC;
	}

	std::cout << "===== testComposite TEST 3 SUCCES" << std::endl;

	Icone3DIterator_const itCompos2 = itIcone->cbegin();
	if (itCompos2->cbegin() != itCompos2->cend())
	{
		std::cout << "===== testComposite TEST 4 ECHEC" << std::endl;
		return TP5_Test::RESULTAT::ECHEC;
	}

	std::cout << "===== testComposite TEST 4 SUCCES" << std::endl;

	PrimitiveParams paramsSph1 = itCompos2->getParameters();
	if(paramsSph1.size() != 1)
	{
		std::cout << "===== testComposite TEST 5 ECHEC" << std::endl;
		return TP5_Test::RESULTAT::ECHEC;
	}

	std::cout << "===== testComposite TEST 5 SUCCES" << std::endl;

	++itCompos2; ++itCompos2;  ++itCompos2;
	PrimitiveParams paramsCyl2 = itCompos2->getParameters();
	if (paramsCyl2.size() != 2)
	{
		std::cout << "===== testComposite TEST 6 ECHEC" << std::endl;
		return TP5_Test::RESULTAT::ECHEC;
	}

	std::cout << "===== testComposite TEST 6 SUCCES" << std::endl;

	//std::cout << m_icone3D << std::endl;

	return TP5_Test::RESULTAT::SUCCES;
}

TP5_Test::RESULTAT TP5_Test::testDecorator()
{
	Point3D resultatTransform1(3., 2., 0.5f);
	Point3D centreTransform = m_cylTransformed.getCenter();

	if (centreTransform != resultatTransform1)
	{
		std::cout << "===== testDecorator TEST 1 ECHEC" << std::endl;
		return TP5_Test::RESULTAT::ECHEC;
	}

	std::cout << "===== testDecorator TEST 1 SUCCES" << std::endl;

	PrimitiveParams paramsCylTransformed = m_cylTransformed.getParameters();
	if(paramsCylTransformed[0] != 6.)
	{
		std::cout << "===== testDecorator TEST 2 ECHEC" << std::endl;
		return TP5_Test::RESULTAT::ECHEC;
	}

	std::cout << "===== testDecorator TEST 2 SUCCES" << std::endl;

	if (paramsCylTransformed[1] != 15.)
	{
		std::cout << "===== testDecorator TEST 3 ECHEC" << std::endl;
		return TP5_Test::RESULTAT::ECHEC;
	}

	std::cout << "===== testDecorator TEST 3 SUCCES" << std::endl;

	m_cylTransformed.setScale(2.);
	paramsCylTransformed = m_cylTransformed.getParameters();
	if (paramsCylTransformed[0] != 4.)
	{
		std::cout << "===== testDecorator TEST 4 ECHEC" << std::endl;
		return TP5_Test::RESULTAT::ECHEC;
	}

	std::cout << "===== testDecorator TEST 4 SUCCES" << std::endl;

	if (paramsCylTransformed[1] != 10.)
	{
		std::cout << "===== testDecorator TEST 5 ECHEC" << std::endl;
		return TP5_Test::RESULTAT::ECHEC;
	}

	std::cout << "===== testDecorator TEST 5 SUCCES" << std::endl;

	m_cylTransformed.setTranslation(Point3D(1., 1., 1.));
	Point3D resultatTransform2(3.5f, 2.5f, 1.);
	if (m_cylTransformed.getCenter() != resultatTransform2)
	{
		std::cout << "===== testDecorator TEST 6 ECHEC" << std::endl;
		return TP5_Test::RESULTAT::ECHEC;
	}

	std::cout << "===== testDecorator TEST 6 SUCCES" << std::endl;

	//std::cout << m_cylTransformed << std::endl;

	return TP5_Test::RESULTAT::SUCCES;
}

TP5_Test::RESULTAT TP5_Test::testVisitor()
{
	VisitorXMLWriter visXML(std::cout);
	bool verbose = true; // Mettre cette variable a false pour reduire l'impression sur la console

	// Le visiteur d'impression en format XML est complet, les tests doivent fonctionner
	if (verbose)
	{
		std::cout << "===== XML de toute l'icone 3D" << std::endl;
		m_icone3D.accept(visXML);

		std::cout << std::endl << "===== XML du cylindre transforme" << std::endl;
		m_cylTransformed.accept(visXML);
	}

	// Selectionner toutes les primitives Cube dans l'icone
	m_selectObjContainer.clear();
	VisitorPrimitiveSelector visSelector(PRIMITIVE_TYPE::Cube_t);
	m_icone3D.accept(visSelector);
	visSelector.getSelectIcones(m_selectObjContainer);

	// Verifier le nombre de primitives Cube selectionnees
	size_t iTest = 1;
	if (m_selectObjContainer.size() != 4)
	{
		std::cout << "===== testVisitor TEST " << iTest << " ECHEC" << std::endl; // Test 1
		return TP5_Test::RESULTAT::ECHEC;
	}
	std::cout << "===== testVisitor TEST " << iTest << " SUCCES" << std::endl; // Test 1
	++iTest;

	if (verbose)
	{
		std::cout << std::endl << "===== XML des Cubes selectionnes" << std::endl;
		for (auto it : m_selectObjContainer)
			it->accept(visXML);
	}

	// Verifier que le nombre de parametre pour chaque primitive est 3
	for (auto it : m_selectObjContainer)
	{
		if (it->getNbParameters() != 3)
		{
			std::cout << "===== testVisitor TEST " << iTest << " ECHEC" << std::endl; // Test 2, 3, 4, 5
			return TP5_Test::RESULTAT::ECHEC;
		}
		std::cout << "===== testVisitor TEST " << iTest << " SUCCES" << std::endl; // Test 2, 3, 4, 5
		++iTest;
	}

	// Changer le type de primitive choisi a Sphere
	// Selectionner toutes les primitives Sphere dans l'icone
	m_selectObjContainer.clear();
	visSelector.setType(PRIMITIVE_TYPE::Sphere_t);
	visSelector.clearSelectIcones();
	m_icone3D.accept(visSelector);
	visSelector.getSelectIcones(m_selectObjContainer);

	// Verifier le nombre de primitives selectionnees
	if (m_selectObjContainer.size() != 4)
	{
		std::cout << "===== testVisitor TEST " << iTest << " ECHEC" << std::endl; // Test 6
		return TP5_Test::RESULTAT::ECHEC;
	}
	std::cout << "===== testVisitor TEST " << iTest << " SUCCES" << std::endl; // Test 6
	++iTest;

	if (verbose)
	{
		std::cout << std::endl << "===== XML des Spheres selectionnes" << std::endl;
		for (auto it : m_selectObjContainer)
			it->accept(visXML);
	}

	// Verifier que le nombre de parametre pour chaque primitive est 1
	for (auto it : m_selectObjContainer)
	{
		if (it->getNbParameters() != 1)
		{
			std::cout << "===== testVisitor TEST " << iTest << " ECHEC" << std::endl; // Test 7, 8, 9, 10
			return TP5_Test::RESULTAT::ECHEC;
		}
		std::cout << "===== testVisitor TEST " << iTest << " SUCCES" << std::endl; // Test 7, 8, 9, 10
		++iTest;
	}

	// Changer le type de primitive choisi a Cylindre
	// Selectionner toutes les primitives Sphere dans l'icone
	m_selectObjContainer.clear();
	visSelector.setType(PRIMITIVE_TYPE::Cylinder_t);
	visSelector.clearSelectIcones();
	m_icone3D.accept(visSelector);
	visSelector.getSelectIcones(m_selectObjContainer);

	// Generer le XML des primitives selectionnees
	// Verifier le nombre de primitives selectionnees
	if (m_selectObjContainer.size() != 3)
	{
		std::cout << "===== testVisitor TEST " << iTest << " ECHEC" << std::endl; // Test 11
		return TP5_Test::RESULTAT::ECHEC;
	}
	std::cout << "===== testVisitor TEST " << iTest << " SUCCES" << std::endl; // Test 11
	++iTest;

	if (verbose)
	{
		std::cout << std::endl << "===== XML des Cylindres selectionnes" << std::endl;
		for (auto it : m_selectObjContainer)
			it->accept(visXML);
	}

	// Verifier que le nombre de parametre pour chaque primitive est 1
	for (auto it : m_selectObjContainer)
	{
		if (it->getNbParameters() != 2)
		{
			std::cout << "===== testVisitor TEST " << iTest << " ECHEC" << std::endl; // Test 12, 13, 14
			return TP5_Test::RESULTAT::ECHEC;
		}
		std::cout << "===== testVisitor TEST " << iTest << " SUCCES" << std::endl; // Test 12, 13, 14
		++iTest;
	}

	return TP5_Test::RESULTAT::SUCCES;
}

TP5_Test::RESULTAT TP5_Test::testCommand()
{
	// Recuperer l'instance de l'invoker
	Invoker* invoker = Invoker::getInstance();

	// S'assurer que la liste des objets selectionnes est vide
	m_selectObjContainer.clear();

	// Construire une commande pour imprimer l'icone en XML
	// Devrait produire une sortie XML sur la console
	CmdPtr cmdPrint = std::make_shared<XMLPrintCmd>(m_icone3D);
	invoker->execute(cmdPrint);

	// Construire une commande pour selectionner les cylindres
	PRIMITIVE_TYPE primType = PRIMITIVE_TYPE::Cylinder_t;
	std::shared_ptr<SelectPrimitiveCmd> selecCmdp = std::make_shared<SelectPrimitiveCmd>(primType, m_icone3D);
	CmdPtr uneCmdp(selecCmdp);
	invoker->execute(uneCmdp);
	selecCmdp->getSelectIcones(m_selectObjContainer);
	if (m_selectObjContainer.size() != 3)
	{
		std::cout << "===== testCommand TEST 1 ECHEC" << std::endl; // Test 1
		return TP5_Test::RESULTAT::ECHEC;
	}
	std::cout << "===== testCommand TEST 1 SUCCES" << std::endl; // Test 1

	// Construire une commande pour transformer tous les cylindres
	float scale = 2.5;
	Point3D translate(0.25, 0.25, 0.25);
	for (auto it : m_selectObjContainer)
	{
		CmdPtr cmdTransform = std::make_shared<TransformCmd>(it, translate, scale);
		invoker->execute(cmdTransform);
	}

	// Verifier que les cylindres ont bien ete transformes
	size_t iTest = 2;
	for (auto it : m_selectObjContainer)
	{
		if (it->getCenter().x() != 3.25)
		{
			std::cout << "===== testCommand TEST " << iTest << " ECHEC" << std::endl; // Test 2, 4, 6
			return TP5_Test::RESULTAT::ECHEC;
		}
		std::cout << "===== testCommand TEST " << iTest << " SUCCES" << std::endl; // Test 2, 4, 6
		++iTest;

		if (it->getParameters()[0] != 2.5)
		{
			std::cout << "===== testCommand TEST " << iTest << " ECHEC" << std::endl; // Test 3, 5, 7
			return TP5_Test::RESULTAT::ECHEC;
		}
		std::cout << "===== testCommand TEST " << iTest << " SUCCES" << std::endl; // Test 3, 5, 7
		++iTest;
	}

	// Verifier que les transformations peuvent etre annulees
	invoker->undo();
	invoker->undo();
	invoker->undo();
	for (auto it : m_selectObjContainer)
	{
		if (it->getCenter().x() != 3.00)
		{
			std::cout << "===== testCommand TEST " << iTest << " ECHEC" << std::endl; // Test 8, 10, 12
			return TP5_Test::RESULTAT::ECHEC;
		}
		std::cout << "===== testCommand TEST " << iTest << " SUCCES" << std::endl; // Test 8, 10, 12
		++iTest;

		if (it->getParameters()[0] != 1.0)
		{
			std::cout << "===== testCommand TEST " << iTest << " ECHEC" << std::endl; // Test 9, 11, 13
			return TP5_Test::RESULTAT::ECHEC;
		}
		std::cout << "===== testCommand TEST " << iTest << " SUCCES" << std::endl; // Test 9, 11, 13
		++iTest;
	}

	// Verifier que les transformations peuvent etre refaites
	invoker->redo();
	invoker->redo();
	invoker->redo();
	for (auto it : m_selectObjContainer)
	{
		if (it->getCenter().x() != 3.25)
		{
			std::cout << "===== testCommand TEST " << iTest << " ECHEC" << std::endl; // Test 14, 16, 18
			return TP5_Test::RESULTAT::ECHEC;
		}
		std::cout << "===== testCommand TEST " << iTest << " SUCCES" << std::endl; // Test 14, 16, 18
		++iTest;

		if (it->getParameters()[0] != 2.5)
		{
			std::cout << "===== testCommand TEST " << iTest << " ECHEC" << std::endl; // Test 15, 17, 19
			return TP5_Test::RESULTAT::ECHEC;
		}
		std::cout << "===== testCommand TEST " << iTest << " SUCCES" << std::endl; // Test 15, 17, 19
		++iTest;
	}

	return TP5_Test::RESULTAT::SUCCES;
}

TP5_Test::RESULTAT TP5_Test::interactivTestCommand()
{
	// Recuperer l'instance de l'invoker
	Invoker* invoker = Invoker::getInstance();

	m_selectObjContainer.clear();

	char c(' ');
	while (c != 'q')
	{
		std::cout << "Entrez une commande:" << std::endl << "p=print,q=quitter,r=redo,s=select,t=transformer,u=undo,x=annuler selection" << std::endl;
		std::cin >> c;
		std::cout << "Caractere entre: " << c << std::endl;

		switch (c)
		{
		case 'p':
		{
			CmdPtr cmdp(nullptr);
			if (m_selectObjContainer.size() == 0)
			{
				cmdp = std::make_shared<XMLPrintCmd>(m_icone3D);
				invoker->execute(cmdp);
			}
			else
			{
				for (auto it : m_selectObjContainer)
				{
					cmdp = std::make_shared<XMLPrintCmd>(*it);
					invoker->execute(cmdp);
				}
			}

		}
		break;
		case 'r': invoker->redo();
			break;
		case 's':
		{
			PRIMITIVE_TYPE type = PRIMITIVE_TYPE::Cube_t;

			std::cout << "Choisissez le type de primitive a selectioner (c=Cube,y=cYlinder,s=Sphere)" << std::endl;
			std::cin >> c;
			std::cout << "Caractere entre: " << c << std::endl;
			switch (c)
			{
			case 'c': type = PRIMITIVE_TYPE::Cube_t; break;
			case 'y': type = PRIMITIVE_TYPE::Cylinder_t; break;
			case 's': type = PRIMITIVE_TYPE::Sphere_t; break;
			default:
				std::cout << "Choix de type invalide, les cubes seront selectionnes" << std::endl;
				type = PRIMITIVE_TYPE::Cube_t;
				break;
			}
			std::shared_ptr<SelectPrimitiveCmd> selecCmdp = std::make_shared<SelectPrimitiveCmd>(type, m_icone3D);
			CmdPtr uneCmdp(selecCmdp);
			invoker->execute(uneCmdp);
			selecCmdp->getSelectIcones(m_selectObjContainer);
			std::cout << "Nombre de primitives selectionnees: " << m_selectObjContainer.size() << std::endl;
		}
		break;
		case 't':
		{
			if (m_selectObjContainer.size() == 0)
			{
				std::cerr << "Aucun objet de selectionne." << std::endl
					<< "Il faut selectionner un type de primitive avant d'appliquer une transformation." << std::endl;
			}
			else
			{
				float scale = 1.0;
				std::cout << "Entrer le facteur de mise a l'echelle:" << std::endl;
				std::cin >> scale;
				std::cout << "Facteur de mise a l'echelle entre:" << scale << std::endl;
				Point3D translate(0.25, 0.25, 0.25);

				for (auto it : m_selectObjContainer)
				{
					CmdPtr cmdp = std::make_shared<TransformCmd>(it, translate, scale);
					invoker->execute(cmdp);
				}
			}
		}
		break;
		case 'u': invoker->undo();
			break;
		case 'x': m_selectObjContainer.clear();
			break;
		}
	}

	return TP5_Test::RESULTAT::SUCCES;
}
