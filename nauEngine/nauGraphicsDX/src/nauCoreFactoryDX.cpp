/*0***0***0***0***0***0***0***0***0***0***0***0***0***0***0***0*/
/**
 * @file nauCoreFactoryDX.cpp
 * @author Marco "Swampy" Millan
 * @date 2019/03/29 2019
 * @brief Member definition
 * 
 */
/*0***0***0***0***0***0***0***0***0***0***0***0***0***0***0***0*/
#include "nauCoreFactoryDX.h"


namespace nauEngineSDK {
  
  //GraphicsAPI*
  //CoreFactoryDX::createGraphicsAPI() {
  //  //return g_graphicsAPI().instancePtr();
  //  return new GraphicsAPIDX();
  //}

  Device*
  CoreFactoryDX::createDevice() {
    return new DeviceDX();
  }

  Shader*
  CoreFactoryDX::createVertexShader() {
    return new VertexShaderDX();
  }

  Shader*
  CoreFactoryDX::createPixelShader() {
    return new PixelShaderDX();
  }

  Texture*
  CoreFactoryDX::createTexture() {
    return new TextureDX();
  }

  InputLayout*
  CoreFactoryDX::createInputLayout() {
    return new InputLayoutDX();
  }

  SamplerState*
  CoreFactoryDX::createSamplerState() {
    return nullptr;
  }

  ViewPort*
  CoreFactoryDX::createViewPort() {
    return nullptr;
  }

  DepthStencil*
  CoreFactoryDX::createDepthStencil() {
    return new DepthStencilDX();
  }

  VertexBuffer*
  CoreFactoryDX::createVertexBuffer() {
    return new VertexBufferDX();
  }

  IndexBuffer*
  CoreFactoryDX::createIndexBuffer() {
    return new IndexBufferDX();
  }

  ConstantBuffer*
  CoreFactoryDX::createConstantBuffer() {
    return new ConstantBufferDX();
  }

}