/*

Name: Kirsty McEwan

Student ID: B00188061

I declare that the following code was produced by Kirsty McEwan, Lauren McNally, Matthew McMahon Wood as a group assignment for the Game Physics module and that this is our own work.

I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.

*/


#include "VerletSolver.h"

void VerletSolver::solver(PhysicsParameters * Parameters, float dt)													//updates at half time intervals rather than updating at each time interval
{
	Parameters->transform.Translate(dt * Parameters->Velocity + 0.5f * dt * dt * Parameters->Acceleration);			//Full time step
	Parameters->Velocity += 0.5f * dt * Parameters->Acceleration;													//Half time step
	Parameters->Acceleration = Parameters->GetResultantForce() * Parameters->GetInverseMass();						// a = f/m (m == inverse mass ~ divide)
	Parameters->Velocity += 0.5f * dt * Parameters->Acceleration;
}
