//https://www.geeks3d.com/hacklab/20200515/demo-rgb-triangle-with-mesh-shaders-in-opengl/

#version 450
#extension GL_NV_mesh_shader : enable

layout(local_size_x=1) in;

layout(max_vertices=3, max_primitives=1) out;

layout(triangles) out;

out PerVertexData
{
  vec4 color;
} v_out[];

uniform mat4 mvp;

const vec3 vertices[3] = {vec3(-1,-1,0), vec3(0,1,0), vec3(1,-1, 0)};
const vec3 colors[3] = {vec3(1.0,0.0,0.0), vec3(0.0,1.0,0.0), vec3(0.0,0.0,1.0)};

void main()
{
  gl_MeshVerticesNV[0].gl_Position = mvp * vec4(vertices[0], 1.0);
  gl_MeshVerticesNV[1].gl_Position = mvp * vec4(vertices[1], 1.0);
  gl_MeshVerticesNV[2].gl_Position = mvp * vec4(vertices[2], 1.0);

  v_out[0].color = vec4(colors[0], 1.0);
  v_out[1].color = vec4(colors[1], 1.0);
  v_out[2].color = vec4(colors[2], 1.0);
  
  gl_PrimitiveIndicesNV[0] = 0;
  gl_PrimitiveIndicesNV[1] = 2;
  gl_PrimitiveIndicesNV[2] = 1;
  
  gl_PrimitiveCountNV = 1;
}