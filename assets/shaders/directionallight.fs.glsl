#version 330 core

in vec3 vPosition_vs; 
in vec3 vNormal_vs; 
in vec2 vTexCoords;
in vec3 vColor;

out vec3 fFragColor;

//uniform sampler2D uTexture;

uniform vec3 uKd;
uniform vec3 uKs;
uniform float uShininess;

uniform vec3 uLightDir_vs;
uniform vec3 uLightIntensity;

vec3 blinnPhong(vec3 uKd,vec3 uKs, float uShininess, vec3 uLightDir_vs, vec3 uLightIntensity) {
    vec3 wi = normalize(uLightDir_vs);
    vec3 w0= normalize(-vPosition_vs);
    vec3 halfVector = (wi + w0)/2;
    return uLightIntensity * ( uKd * dot(wi,vNormal_vs) + uKs * pow(dot(halfVector,vNormal_vs),uShininess));
}

void main() {
	//vec3 texture_color = texture(uTexture, vTexCoords).xyz;
	//fFragColor = texture_color * blinnPhong();
	fFragColor = vColor;
	// + blinnPhong(uKd, uKs, uShininess, uLightDir_vs, uLightIntensity);
}