#version 330

// Input vertex attributes (from vertex shader)
in vec2 fragTexCoord;
in vec4 fragColor;

// Output fragment color
out vec4 finalColor;

#define MAX_SPOTS 99
#define RADIUS 250

struct Spot {
    vec2 pos;		// window coords of spot
};

uniform Spot spots[MAX_SPOTS];      // Spotlight positions array
uniform int current;
uniform vec2 offset;

void main()
{
	float alpha = 1.0;

	vec2 pos = vec2(gl_FragCoord.xy) - offset;

	float d = 65000;

    for (int i = 0; i < current; i++)
    {
		d = distance(pos, spots[i].pos);


		if (d > RADIUS)
		{
			if (alpha < 1.0) continue;
			alpha = 1.0;
		}
		else
		{
			float candidate = d/RADIUS;
			if (candidate > alpha) continue;
			alpha = candidate;
		}
    }

	finalColor = vec4(0, 0, 0, alpha);
}