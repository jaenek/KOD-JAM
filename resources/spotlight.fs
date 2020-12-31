#version 100

precision mediump float;

#define MAX_SPOTS 99
#define ENTRY_EXIT_RADIUS 100
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

	float d;

    for (int i = 0; i < MAX_SPOTS; i++)
    {
		if (i == current) break;
		float radius = float((i > 1) ? RADIUS : ENTRY_EXIT_RADIUS);

		d = distance(pos, spots[i].pos);

		if (d > radius)
		{
			if (alpha < 1.0) continue;
			alpha = 1.0;
		}
		else
		{
			float candidate = d/radius;
			if (candidate > alpha) continue;
			alpha = candidate;
		}
    }

	gl_FragColor = vec4(0, 0, 0, alpha);
}