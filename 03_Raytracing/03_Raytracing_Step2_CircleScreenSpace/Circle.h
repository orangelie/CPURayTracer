#pragma once

#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtx/string_cast.hpp>
#include <glm/gtx/norm.hpp>

namespace hlab
{
	class Circle
	{
	public:
		glm::vec2 center;
		float radius;
		float radiusSquared;
		glm::vec4 color;

		Circle(const glm::vec2 &center, const float radius, const glm::vec4 &color)
			: center(center), color(color), radius(radius)
		{
		}

		// x는 벡터이기 때문에 내부적으로 x좌표와 y좌표를 모두 갖고 있음
		// screen 좌표계에서는 x좌표와 y좌표가 int지만 float로 변환
		bool IsInside(const glm::vec2 &x)
		{
			if (std::sqrtf((x.x - center.x) * (x.x - center.x) + (x.y - center.y) * (x.y - center.y)) <= radius)
				return true;

			return false;
		}
	};
}
