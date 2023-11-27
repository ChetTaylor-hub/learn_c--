#include <iostream>
#include "WorkSpace.h"
#include "zlib.h"

enum Status
{
    exitAll,
    addOne,
    deleteOne,
    displayAll,
    fineOne,
    sortAll,
    editOne,
    clearAll
};

int main(int, char **)
{
    int mode;
    WorkSpace workspace;
    while (1)
    {
        workspace.Display();

        std::cout << "请选择功能：" << std::endl;
        std::cin >> mode;

        switch (mode)
        {
        case exitAll:
            workspace.Exit();
            break;
        case addOne:
            workspace.AddOne();
            break;
        case deleteOne:
            workspace.DeleteOne();
            break;
        case displayAll:
            workspace.DisplayAll();
            break;
        case fineOne:
            workspace.FindOne();
            break;
        case sortAll:
            workspace.SortAll();
            break;
        case editOne:
            workspace.EditOne();
            break;
        case clearAll:
            workspace.ClearAll();
            break;
        default:
            break;
        }

        std::system("pause");
    }
}
