using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class GridManager : MonoBehaviour
{
    [HideInInspector] //hides the following public variable (up to the statement terminator ";") in the Inspector
    public GameObject gridHolder;
    public Square squarePrefab; //assign in Inspector on Grid_Manager to Assets/Prefabs/Square
    public float startX = 0;
    public float startY = 0;
    public int rows;
    public int cols;
    readonly float spacer = 0.05f; //readonly means what it says: spacer is not writable during runtime

    public Text nameTF; //Drag Grid_Name from Hierarchy to assign.
    public Text rowTF; //Drag Grid_Row from Hierarchy to assign.
    public Text colTF; //Drag Grid_Col from Hierarchy to assign.

    // GridManager will appear to be a public static class.
    private static GridManager instance;

    public GameObject player;
    
    void InitGridHolder()
    {
        gridHolder = new GameObject();
        gridHolder.name = "Grid_Holder";
        gridHolder.transform.position = new Vector2(startX, startY);
    }

    void BuildGrid()
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                Square square = Instantiate(squarePrefab, gridHolder.transform);
                Vector2 newPos = new Vector2(j + (spacer * j), i + (spacer * i));
                square.transform.localPosition = newPos;
                square.name = "Square_" + i + "_" + j;
                square.gridPosition = new Vector2Int(i, j);
            }
        }
    }

    void Start()
    {
        // squarePrefab = Resources.Load<Square>("Prefabs/Square");
        // avoid using Resources if you want to build the project see:
        // https://unity3d.com/learn/tutorials/topics/best-practices/resources-folder

        InitGridHolder();
        BuildGrid();
        instance = this; //the key to creating a singleton
    }

    public static void UpdateUI(Square square = null)
    {
        if (square == null)
        {
            instance.nameTF.text = "---";
            instance.rowTF.text = "---";
            instance.colTF.text = "---";
            return;
        }

        instance.nameTF.text = square.name;
        instance.colTF.text = square.gridPosition.x.ToString();
        instance.rowTF.text = square.gridPosition.y.ToString();
    }

    public static void OnDown(Square square = null)
    {
        //instance.player.GetComponent<Player>().MovePlayer(square);
        instance.player.GetComponent<Player>().LerpPlayer(square);
    }
}