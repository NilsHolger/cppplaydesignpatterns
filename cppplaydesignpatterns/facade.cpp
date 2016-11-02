#include "headers.h"

using namespace std;

class MissDepartment
{
public:
	void submitNetworkRequest()
	{
		_state = 0;
	}
	bool checkOnStatus()
	{
		_state++;
		return (_state == Complete) ? 1 : 0;
	}
private:
	enum States
	{
		Received, DenyAllKnowledge, ReferClientToFacilities,
		FacilitiesHasNotSentPaperwork, ElectricianIsNotDone,
		ElectricianDidItWrong, DispatchTechnician, SignedOff, DoesNotWork,
		FixElectriciansWiring, Complete
	};
	int _state;
};

class ElectricianUnion
{
public:
	void submitNetworkRequest()
	{
		_state = 0;
	}
	bool checkOnStatus()
	{
		_state++;
		return (_state == Complete) ? 1 : 0;
	}
private:
	enum States
	{
		Received, RejectTheForm, SizeTheJob, SmokeAndJokeBreak,
		WaitForAuthorization, DoTheWrongJob, BlameTheEngineer, WaitToPunchOut,
		DoHalfAJob, ComplainToEngineer, GetClarification, CompleteTheJob,
		TurnInThePaperwork, Complete
	};
	int _state;
};

class FacilitiesDepartment
{
public:
	void submitNetworkRequest()
	{
		_state = 0;
	}
	bool checkOnStatus()
	{
		_state++;
		return (_state == Complete) ? 1 : 0;
	}
private:
	enum States
	{
		Received, AssignToEngineer, EngineerResearches, RequestIsNotPossible,
		EngineerLeavesCompany, AssignToNewEngineer, NewEngineerResearches,
		ReassignEngineer, EngineerReturns, EngineerResearchesAgain,
		EngineerFillsOutPaperWork, Complete
	};
	int _state;
};

class FacilitiesFacade
{
public:
	FacilitiesFacade()
	{
		_count = 0;
	}
	void submitNetworkRequest()
	{
		_state = 0;
	}
	bool checkOnStatus()
	{
		_count++;
		if (_state == Received)
		{
			_state++;
			_engineer.submitNetworkRequest();
			cout << "submitted to Facilities - " << _count <<
				" phone calls so far" << '\n';
		}
		else if (_state == SubmitToEngineer)
		{
			if (_engineer.checkOnStatus())
			{
				_state++;
				_electrician.submitNetworkRequest();
				cout << "submitted to Electrician - " << _count <<
					" phone calls so far" << '\n';
			}
		}
		else if (_state == SubmitToElectrician)
		{
			if (_electrician.checkOnStatus())
			{
				_state++;
				_technician.submitNetworkRequest();
				cout << "submitted to MISS - " << _count <<
					" phone calls so far" << '\n';
			}
		}
		else if (_state == SubmitToTechnician)
		{
			if (_technician.checkOnStatus()){
				return 1;
			}
		}
		return 0;
	}
	int getNumberOfCalls()
	{
		return _count;
	}
private:
	enum States
	{
		Received, SubmitToEngineer, SubmitToElectrician, SubmitToTechnician
	};
	int _state, _count;
	FacilitiesDepartment _engineer;
	ElectricianUnion _electrician;
	MissDepartment _technician;
};

//auto main()	-> int
//{
//	FacilitiesFacade facade;
//	facade.submitNetworkRequest();
//	while (!facade.checkOnStatus()){
//		;
//	}
//	cout << "job completed after " << facade.getNumberOfCalls() <<
//		" phone calls" << '\n';
//	getchar();
//}