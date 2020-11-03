#include<bits/stdc++.h>

using namespace std;

class CarSpeedUtils {
    public:
        double acc;
        double maxSpeed;
        double distD;
        double distL;
        double speedLimit;

   double findOptimalTime() {
        if (maxSpeed <= speedLimit) {
            return findSimpleTime();
        } else {
            return findComplexTime();
        }
    }

    private:
     double findComplexTime() {
        double distanceToReachSpeedLimit = (speedLimit*speedLimit)/(2*acc);
        double distanceToReachMaxSpeed = (maxSpeed*maxSpeed)/(2*acc);

        if (distanceToReachSpeedLimit >= distL || (distanceToReachSpeedLimit >= distD && distanceToReachMaxSpeed >= distL) ) {
            return sqrt((2*distL)/acc);
        } else if (distanceToReachSpeedLimit >= distD) {
            double initialTime = maxSpeed/acc;
            double remainingTime = (distL-distanceToReachMaxSpeed)/maxSpeed;
            return (remainingTime + initialTime);
        } else {
        	double midSpeed = sqrt(((2*acc*distD)+(speedLimit*speedLimit))/2);
        	double initialTime = 0;
        	if (midSpeed <= maxSpeed) {
        		double initialTime1 = midSpeed/acc;
        		double initialTime2 = (midSpeed-speedLimit)/acc;
        		initialTime = initialTime1 + initialTime2;
        	} else {
        		double initialTime1 = maxSpeed/acc;
        		double initialTime2 = (maxSpeed-speedLimit)/acc;
        		double distance1 = (maxSpeed*maxSpeed)/(2*acc);
        		double distance2 = ((maxSpeed*maxSpeed)-(speedLimit*speedLimit))/(2*acc);
        		double initialTime3 = (distD - distance1 - distance2)/maxSpeed;
        		initialTime = initialTime1 + initialTime2 + initialTime3;
        	}



            double distanceLimitToMax = ((maxSpeed*maxSpeed)-(speedLimit*speedLimit))/(2*acc);
            if (distanceLimitToMax > (distL - distD)) {
                double finalSpeed = sqrt(speedLimit*speedLimit+2*acc*(distL-distD));
                return (initialTime+((finalSpeed-speedLimit)/acc));
            }

            double maxSpeedTime = (maxSpeed-speedLimit)/acc;
            double maxSpeedDistance = (maxSpeed*maxSpeed - speedLimit*speedLimit)/(2*acc);
            double remainingDistance = distL - distD - maxSpeedDistance;
            double remainingTime = remainingDistance/maxSpeed;
            return (initialTime + maxSpeedTime + remainingTime);
        }
    }

    double findSimpleTime() {
        double initialTime = maxSpeed/acc;
        double initialDistance = 0.5 * acc * pow(initialTime, 2);
        if (initialDistance >= distL) {
            return sqrt((2*distL)/acc);
        }
        double remainingTime = (distL - initialDistance)/maxSpeed;
        return initialTime+remainingTime;
    }
};

int main(){

    CarSpeedUtils carUtils;
    cin >> carUtils.acc >> carUtils.maxSpeed;
    cin >> carUtils.distL >> carUtils.distD >> carUtils.speedLimit;
    cout << fixed << setprecision(9) << carUtils.findOptimalTime();

    return 0;
}
