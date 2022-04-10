#pragma once

class Renderer
{
public:
    Renderer();
    ~Renderer();

    static void Init();
    static void Shutdown();

    static void RenderQuad();

private:
    void StartBatch();
    void FlushAndReset();

private:

};