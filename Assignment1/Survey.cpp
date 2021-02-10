#include "Survey.h"

#include <iomanip>


ostream& operator<<(ostream& out, vector<NonGamingStudent*>& ng)
{

	const string service[4] = { "Netflix","Crave","Disney+","Hulu" };
	double SumAge = 0, AvgAge;
	double SumHours = 0, AvgHours;
	int ServiceTally[4] = { 0,0,0,0 }, PreferredService = 0;
	for (int i = 0; i < ng.size(); i++)
	{
		SumAge += ng[i]->GetAge();
		SumHours += ng[i]->GetHours();
		ServiceTally[ng[i]->GetService()]++;
	}
	AvgAge = SumAge / ng.size();
	AvgHours = SumHours / ng.size();
	for (int s = 1; s < 4; s++) { if (ServiceTally[s] > ServiceTally[PreferredService]) { PreferredService = s; } }
	out << fixed << setprecision(2) << "----- Non-Gaming Student -----\nNumber of Students: " << ng.size() << "\nAverage Age: " << AvgAge << "\nPreferred Streaming Service: " << service[PreferredService] << "\nAverage hours spent consuming non-gaming entertainment: " << AvgHours << endl;
	return out;
}


ostream& operator<<(ostream& out, vector<GamingStudent*>& g)
{
	const string device[4] = { "Computer","Console","Phone","Tablet" };
	double SumAge = 0, AvgAge;
	double SumHours = 0, AvgHours;
	int DeviceTally[4] = { 0,0,0,0 }, PreferredDevice = 0;
	for (int i = 0; i < g.size(); i++)
	{
		SumAge += g[i]->GetAge();
		SumHours += g[i]->GetHours();
		DeviceTally[g[i]->GetDevice()]++;
	}
	AvgAge = SumAge / g.size();
	AvgHours = SumHours / g.size();
	for (int d = 1; d < 4; d++) { if (DeviceTally[d] > DeviceTally[PreferredDevice]) { PreferredDevice = d; } }
	out << fixed << setprecision(2) << "----- Gaming Student -----\nNumber of Students: " << g.size() << "\nAverage Age: " << AvgAge << "\nPreferred Gaming Device: " << device[PreferredDevice] << "\nAverage hours spent consuming gaming entertainment: " << AvgHours << endl;
	return out;
}


void Survey::Process()
{
	if (NonGaming.size() > 0) { cout << NonGaming << endl; }
	if (Gaming.size() > 0) { cout << Gaming; }
}
