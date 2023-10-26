# FairyIsland
The Game Engine Of FairyIsland

# Submodule Modify

## ImGui
if you got the error: `DC undeclare`

```cpp
// FairyIsland/vendor/imgui/imgui.h 
// line: 3839

    // for (int i = 0; window && i < window->DC.Layouts.Data.Size; i++)
    // {
    //     ImGuiLayout* layout = (ImGuiLayout*)window->DC.Layouts.Data[i].val_p;
    //     IM_DELETE(layout);
    // }
```
