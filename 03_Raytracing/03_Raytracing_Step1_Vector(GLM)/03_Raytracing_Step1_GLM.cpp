#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtx/string_cast.hpp> // cout ����� ���� string_cast()

#include <DirectXMath.h> // DirectXMath�� glm �񱳿�

using namespace std; // cout, endl;
using namespace glm;
using namespace DirectX;

int main()
{
    /*
    * glm ��ġ
    * vcpkg install glm:x64-windows
    */

    /*
    * glm�� �⺻���� ��� ���
    */

    // ���� �����ϴ� ��� (vec3, vec4 � �־��)
    glm::vec3 a(1.0f, 2.0f, 3.0f);
    glm::vec3 b(7.0f, 8.0f, 9.0f);

    // ���͸� cout���� ���ڿ��� �ٲ㼭 ����ϴ� ���
    cout << glm::to_string(b - a) << endl;

    // ���ͳ��� ���ϱ� ���� ����
    auto c = b - a; // b + a

    cout << "a = " << glm::to_string(a) << endl;
    cout << "b = " << glm::to_string(b) << endl;
    cout << "b - a = " << glm::to_string(c) << endl;

    // ���Ϳ� ��Į��(���� �ϳ�)�� ���ϸ� ������ ��� ���ҿ� ���ϱ�
    c = a * 10.0f; 

    cout << "c = a * 10.0f; "<< glm::to_string(c) << endl;

    // ������ ���� ���ϱ�
    float l = glm::length(c);

    cout << (b - a).length() << endl; // float�� to_string �� �ʿ䰡 ����

    // ���͸� ���̰� 1.0�� ����(unit) ���ͷ� �����
    auto u = glm::normalize(b - a);
    // auto u = (b-a) / glm::length(b-a)
    cout << glm::length(u) << endl;

    /* ����: ���̰� 0.0�� ���͸� ���� ���ͷ� ������� �õ��ϸ� ���� �߻�
    
    if (glm::length(u) < 1e-4f) {
        // �ٸ� ������� ó��
    }

    if (glm::dot(u, u) < 1e-16f) { // sqrt()�� ���ϱ� ���� dot ���
        // �ٸ� ������� ó��
    }

    */

    // ����(inner product, dot product)
    auto aDotB = glm::dot(a, b);

    cout << aDotB << endl; // ������ ����� float�� to_string �� �ʿ䰡 ����

    cout << dot(vec3(1, 0, 0), vec3(0, 1, 0)) << endl; // 0
    cout << dot(vec3(1, 2, 3), vec3(1, 2, 3)) << endl; // 1*1 + 2*2 + 3*3 = 14

    // ����(outer product, cross product)
    // �������� normal�� ���� ���� a�� b�� unit vector ���� ��
    auto aCrossB = glm::cross(a, b); 
    
    cout << to_string(aCrossB) << endl; // ������ ����� ����
    cout << to_string(cross(vec3(1, 0, 0), vec3(0, 1, 0))) << endl; // vec3(0.0, 0.0, 1.0)
    cout << length(cross(vec3(1.5, 0, 0), vec3(0, 2, 0))) << endl; // 3

    /* ��Ÿ ��� ����� */
    glm::vec4 v4(glm::vec3(2.0f), 1.0f);

    glm::vec3 v3 = { 2.0f, 4.0f, 6.0f}; // List initialization
    // glm::vec3 v3 = vec3{ 2.0f, 2.0f, 2.0f};
    // glm::vec3 v3 = vec3( 2.0f, 2.0f, 2.0f);
    // glm::vec3 v3 = vec3(2.0f); // ��� ���� ������ �ʱ�ȭ�� ���

    std::cout << v3.x << " " << v3.y << " " << v3.z << std::endl; // 2 4 6
    std::cout << v3.r << " " << v3.g << " " << v3.b << std::endl; // 2 4 6
    std::cout << v3[0] << " " << v3[1] << " " << v3[2] << std::endl; // 2 4 6

    /*
    * Double (�������� ���е��� ���ƾ� �ؼ� double�� ����ϴ� ��쵵 ����)
    */
    auto doubleVector = glm::dvec3(1.0, 2.0, 3.0);

    /*
    * DirectXMath ���� GLM�� �� �������̿���.
    */

    // DirectXMath�� �̿��ؼ� ������ ���̸� ���ϴ� ���
    XMFLOAT4 xfloat4 = { 1.0f, 2.0f, 3.0f, 1.0f };
    auto xvector = XMLoadFloat4(&xfloat4);
    xvector = XMVector3Length(xvector); // sqrt(1*1 + 2*2 + 3*3), �Լ� �̸��� XMVector ����3 Length() �Դϴ�.

    float length;
    XMStoreFloat(&length, xvector);

    cout << "DirectXMath Length = " << length << endl;
    cout << sqrt(1.0 * 1.0 + 2.0 * 2.0 + 3.0 * 3.0) << endl;

    // GLM�� �̿��ؼ� ������ ���̸� ���ϴ� ���
    {
        glm::vec3 v = { 1.0f, 2.0f, 3.0f };
        const float length = glm::length(v); // sqrt(1*1 + 2*2 + 3*3)
        cout << "GLM length = " << length << endl;
    }
}
