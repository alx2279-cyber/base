#pragma once
#include <cmath>

struct Vector2 {
    float x, y;
    Vector2() : x(0), y(0) {}
    Vector2(float x, float y) : x(x), y(y) {}
};

struct Vector3 {
    float x, y, z;
    Vector3() : x(0), y(0), z(0) {}
    Vector3(float x, float y, float z) : x(x), y(y), z(z) {}

    float Distance(Vector3 other) {
        return sqrtf(powf(other.x - x, 2) + powf(other.y - y, 2) + powf(other.z - z, 2));
    }
};

struct Vector4 {
    float x, y, z, w;
    Vector4() : x(0), y(0), z(0), w(0) {}
    Vector4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}
};

struct Matrix4x4 {
    float m[4][4];
};

namespace Math {
    // Basic WorldToScreen skeleton for AI to fill based on game's specific math
    inline bool WorldToScreen(Vector3 worldPos, Vector2& screenPos, float matrix[16], int windowWidth, int windowHeight) {
        float clip_x = worldPos.x * matrix[0] + worldPos.y * matrix[1] + worldPos.z * matrix[2] + matrix[3];
        float clip_y = worldPos.x * matrix[4] + worldPos.y * matrix[5] + worldPos.z * matrix[6] + matrix[7];
        float clip_z = worldPos.x * matrix[8] + worldPos.y * matrix[9] + worldPos.z * matrix[10] + matrix[11];
        float clip_w = worldPos.x * matrix[12] + worldPos.y * matrix[13] + worldPos.z * matrix[14] + matrix[15];

        if (clip_w < 0.1f)
            return false;

        Vector3 ndc;
        ndc.x = clip_x / clip_w;
        ndc.y = clip_y / clip_w;
        ndc.z = clip_z / clip_w;

        screenPos.x = (windowWidth / 2 * ndc.x) + (ndc.x + windowWidth / 2);
        screenPos.y = -(windowHeight / 2 * ndc.y) + (ndc.y + windowHeight / 2);

        return true;
    }
}
