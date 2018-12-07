struct VertexInputType
{
  float4 position : POSITION;
  float4 color : COLOR;
};

struct PixelInputType
{
  float4 position : SV_POSITION;
  float4 color : COLOR;
};

PixelInputType ColorVertexShader(VertexInputType input)
{
  PixelInputType output;
  output.color = input.color;
  output.position = input.position;
  output.position.w = 1.0f;
  return output;
}