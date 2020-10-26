using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
public class GameManager : MonoBehaviour
{
    [HideInInspector] //hides the following public variable (up to the statement terminator ";") in the Inspector
    public GameObject gridHolder;
    public Square squarePrefab; //assign in Inspector on Grid_Manager to Assets/Prefabs/Square
    public float startX = 0;
    public float startY = 0;
    public int rows;
    public int cols;
    readonly float spacer = 0.1f; //readonly means what it says: spacer is not writable during runtime
    public Text nameTF; //Drag Grid_Name from Hierarchy to assign.
    public Text rowTF; //Drag Grid_Row from Hierarchy to assign.
    public Text colTF; //Drag Grid_Col from Hierarchy to assign.
    //public GameObject player;
    //An array that holds colors for squares
    public Color[] squareColorsArray;
    //A list to randomize and assign colors 
    public List<Color> squareColorsList = new List<Color>();
    Square firstSquare;
    Square secondSquare;
    // GridManager will appear to be a public static class.
    private static GameManager instance;
    // Start is called before the first frame update
    void Start()
    {
        // squarePrefab = Resources.Load<Square>("Prefabs/Square");
        // avoid using Resources if you want to build the project see:
        // https://unity3d.com/learn/tutorials/topics/best-practices/resources-folder
        InitGridHolder();
        ColorsArrayToList();
        BuildGrid();
        instance = this; //the key to creating a singleton
    }
    void InitGridHolder()
    {
        gridHolder = new GameObject();
        gridHolder.name = "Grid_Holder";
        gridHolder.transform.position = new Vector2(startX, startY);
    }
    // Define colors in the squareColorsArray in the Unity Editor under GameManager
    void ColorsArrayToList()
    {
        //instance.squareColorsList = new List<Color>();
        foreach (Color color in squareColorsArray)
        {
            squareColorsList.Add(color);
            squareColorsList.Add(color);
        }
    }
    public Color GetRandomColor()
    {
        int rNum = Random.Range(0, squareColorsList.Count);
        Color color = squareColorsList[rNum];
        squareColorsList.RemoveAt(rNum);
        return color;
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
                square.hiddenColor = GetRandomColor();
            }
        }
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
        instance.colTF.text = square.gridPosition.y.ToString();
        instance.rowTF.text = square.gridPosition.x.ToString();
    }
    public static void OnDown(Square square = null)
    {
        //instance.player.GetComponent<Player>().MovePlayer(square);
        //instance.player.GetComponent<Player>().LerpPlayer(square);
        if (instance.firstSquare == null)
        {
            instance.FirstTurn(square);
        }
        else
        {
            instance.SecondTurn(square);
        }
    }
    void FirstTurn(Square square = null)
    {
        instance.firstSquare = square;
        square.ShowColor();
    }
    void SecondTurn(Square square = null)
    {
        if (instance.secondSquare == null)
        {
            instance.secondSquare = square;
            square.ShowColor();
            StartCoroutine(instance.CheckMatch(firstSquare, secondSquare));
        }
    }
    IEnumerator CheckMatch(Square firstSquare, Square secondSquare)
    {
        yield return new WaitForSeconds(1);
        Debug.Log("CheckMatch");
        if (firstSquare.GetColor() == secondSquare.GetColor() && firstSquare != secondSquare)
        {
            Match();
            Debug.Log("Match");
        }
        else
        {
            NoMatch(firstSquare, secondSquare);
            Debug.Log("NoMatch");
        }
    }
    void Match()
    {
        instance.firstSquare.SetActive(false);
        instance.secondSquare.SetActive(false);
        instance.firstSquare = null;
        instance.secondSquare = null;
    }
    void NoMatch(Square firstSquare, Square secondSquare)
    {
        instance.firstSquare.ResetColor();
        instance.secondSquare.ResetColor();
        instance.firstSquare = null;
        instance.secondSquare = null;
    }
}