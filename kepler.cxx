#include <iostream>
#include <fstream>
#include <cmath>
#include <sstream>
#include <string>

using namespace std;

static double q[2];
static double p[2];

static double H;

static double e = 0.6;

static double t0 = 0;
static double t_end = 20*M_PI;

static double dt1 = 0.05;
static double dt2 = 0.0005;


void step (const double dt);
void init ();



void step (const double dt) {

	// iterate one step of p
	p[0] -= dt * q[0]/(pow(q[0]*q[0]+q[1]*q[1], 3/2.));
	p[1] -= dt * q[1]/(pow(q[0]*q[0]+q[1]*q[1], 3/2.));

	// use the next steps p to calculate the following q
	q[0] += dt * p[0];
	q[1] += dt * p[1];

	// calculate the energy of the system
	H = 0.5*(p[0]*p[0] + p[1]*p[1]) - 1/sqrt(q[0]*q[0] + q[1]*q[1]);
}

void init () {

	//  set initial conditions
	q[0] = 1-e;
	q[1] = 0;

	p[0] = 0;
	p[1] = sqrt((1+e)/(1-e));

	// calculate the energy of the system
	H = 0.5*(p[0]*p[0] + p[1]*p[1]) - 1/sqrt(q[0]*q[0] + q[1]*q[1]);
}

int main () {

	double dt;

	// init values, set first value of dt
	init();
	dt = dt1;

	// iterate name of output file
	stringstream strm;

	strm.str("");
	strm << "data_dt_" << dt;

	// open the file
	ofstream out(strm.str().c_str());

	// write initial conditions
	out << t0 << "\t" << H << "\t" << q[0] << "\t" << q[1]  << endl;

	// iterate over all timesteps
	for (double t=t0; t<= t_end; t+=dt) {
		// calculate one step and write to file
		step(dt);
		out << t << "\t" << H << "\t" << q[0] << "\t" << q[1]  << endl;
	}

	// close the filestream 
	out.close();

	// reset initial values, change dt
	init();
	dt = dt2;

	// change filename
	strm.str("");
	strm << "data_dt_" << dt;

	// open the file
	out.open(strm.str().c_str());

	// write initial conditions
	out << t0 << "\t" << H << "\t" << q[0] << "\t" << q[1]  << endl;

	// iterate over all timesteps
	for (double t=t0; t<= t_end; t+=dt) {
		// calculate one step and write to file
		step(dt);
		out << t << "\t" << H << "\t" << q[0] << "\t" << q[1]  << endl;
	}

	// close the filestream 
	out.close();

}