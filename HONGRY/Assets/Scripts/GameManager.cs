using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.SceneManagement;

public class GameManager : MonoBehaviour
{
    [HideInInspector] //hides the following public variable (up to the statement terminator ";") in the Inspector
    public GameObject gridHolder;
    public Square squarePrefab; //assign in Inspector on Grid_Manager to Assets/Prefabs/Square
    public float startX = 0;
    public float startY = 0;
    public int rows, cols;
    public static int numOfEnemyTypes = 2;
    public float wait, next;
    readonly float spacer = 0.05f; //readonly means what it says: spacer is not writable during runtime
    public GameObject [] enemy = new GameObject [numOfEnemyTypes];

    public Text nameTF; //Drag Grid_Name from Hierarchy to assign.
    public Text rowTF; //Drag Grid_Row from Hierarchy to assign.
    public Text colTF; //Drag Grid_Col from Hierarchy to assign.

    // GridManager will appear to be a public static class.
    private static GameManager instance;

    public GameObject player;

    public Text timerText;
    private float startTime;
    public string sceneName;
    static int timer;
    
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
        startTime = Time.time; 
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

    void Update()
    {
        GameObject enemySpawn = enemy[Random.Range(0, numOfEnemyTypes)];
        Vector2 respawnPos = new Vector2(0, 0);
        next = Time.time + wait;//increasing the time until next spawn by however much the wait time is
        Instantiate(enemySpawn, respawnPos, Quaternion.identity);//instantiate a new enemy
        float t = Time.time - startTime;

        int seconds = (int)t;

        timer = 250 - seconds;

        timerText.text = timer.ToString();

        if (timerText.text == "0")
            SceneManager.LoadScene (sceneName);
    }

    public static void OnDown(Square square = null)
    {
        //instance.player.GetComponent<Player>().MovePlayer(square);
        instance.player.GetComponent<Player>().LerpPlayer(square);
    }

    public static void addTime(int add)//adds time to the timer
    {
        timer += add;
    }
}