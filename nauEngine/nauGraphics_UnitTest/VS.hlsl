cbuffer ConstantBuffer{

    float4x4 World;
    float4x4 View;
    float4x4 Projection;
};
struct VertexInputType
{
    float4 position : POSITION0;
    float4 color : COLOR0;
    float4 normal : NORMAL0;
    float2 texcoord : TEXCOORD0;
};
struct PixelInputType
{
    float4 position : SV_POSITION;
    float4 color : COLOR0;
    float2 texcoord : TEXCOORD0;
};

PixelInputType ColorVertexShader(VertexInputType input)
{
    PixelInputType output;
    output.color = input.color;
    //output.position = mul(World, input.position);
    output.position = input.position;
    output.position.w = 1.0f;
    output.texcoord = input.texcoord;
    return output;
}