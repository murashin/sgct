/*************************************************************************
Copyright (c) 2012 Miroslav Andel, Link�ping University.
All rights reserved.
 
Original Authors:
Miroslav Andel, Alexander Fridlund

For any questions or information about the SGCT project please contact: miroslav.andel@liu.se

This work is licensed under the Creative Commons Attribution-ShareAlike 3.0 Unported License.
To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/3.0/ or send a letter to
Creative Commons, 444 Castro Street, Suite 900, Mountain View, California, 94041, USA.
 
THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
"AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE
COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
OF THE POSSIBILITY OF SUCH DAMAGE.
*************************************************************************/

#ifndef _USER_H_
#define _USER_H_

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "Frustum.h"

namespace core_sgct
{

/*!
Helper class for setting user variables
*/
class User
{
public:
	User()
	{
		for(unsigned int i=0; i<3; i++)
			mPos[i] = glm::vec3(0.0f);
		mEyeSeparation = 0.069f;
	}

	void setPos(float x, float y, float z)
	{
		mPos[Frustum::Mono].x = x;
		mPos[Frustum::Mono].y = y;
		mPos[Frustum::Mono].z = z;
		updateEyeSeparation();
	}

	void setPos(double * pos)
	{
		mPos[Frustum::Mono].x = static_cast<float>(pos[0]);
		mPos[Frustum::Mono].y = static_cast<float>(pos[1]);
		mPos[Frustum::Mono].z = static_cast<float>(pos[2]);
		updateEyeSeparation();
	}

	void setEyeSeparation(float eyeSeparation)
	{
		mEyeSeparation = eyeSeparation;
		updateEyeSeparation();
	}

	glm::vec3 getPos() { return mPos[Frustum::Mono]; }
	glm::vec3 getPos(Frustum::FrustumMode fm) { return mPos[fm]; }
	glm::vec3 * getPosPtr() { return &mPos[Frustum::Mono]; }
	glm::vec3 * getPosPtr(Frustum::FrustumMode fm) { return &mPos[fm]; }

	float getEyeSeparation() { return mEyeSeparation; }

private:
	void updateEyeSeparation()
	{
		mPos[Frustum::StereoLeftEye].x = mPos[Frustum::Mono].x - mEyeSeparation/2.0f;
		mPos[Frustum::StereoLeftEye].y = mPos[Frustum::Mono].y;
		mPos[Frustum::StereoLeftEye].z = mPos[Frustum::Mono].z;

		mPos[Frustum::StereoRightEye].x = mPos[Frustum::Mono].x + mEyeSeparation/2.0f;
		mPos[Frustum::StereoRightEye].y = mPos[Frustum::Mono].y;
		mPos[Frustum::StereoRightEye].z = mPos[Frustum::Mono].z;
	}

private:
	glm::vec3 mPos[3];
	float mEyeSeparation;
};

} // sgct

#endif