Texture2D shaderTexture : register (t0);
SamplerState SampleType : register (s0);
cbuffer ConstantBuffer{
  float4x4 World;
  float4x4 View;
  float4x4 Projection;
};
struct VertexInputType
{
  float4 position : POSITION;
  float4 color : COLOR;
};
struct PixelInputType
{
  float4 position : SV_POSITION;
  float4 color : COLOR;
  float2 texcoord : TEXCOORD0;
};

float4 ColorPixelShader(PixelInputType input) : SV_TARGET
{
  //return input.color;
	return shaderTexture.Sample(SampleType, input.texcoord);

}
