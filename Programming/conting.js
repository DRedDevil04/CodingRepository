import { useEffect, useContext, useState } from "react";
import { useLocation, useNavigate } from "react-router-dom";
import { get, ref, remove } from "firebase/database";
import { Table, Button, Modal, message } from "antd";
import {} from "antd";
import { PDFDownloadLink } from "@react-pdf/renderer";

import sports from "../../utils/sports.json";
import empSports from "../../utils/empsports.json";
import { database } from "../../firebase";
import { UserContext } from "../../utils/UserContext";
import DownloadPDF from "./DownloadPDF";

export default function Contingency() {
  /*
    Data object=
      "2022035":{
        name:"devam"
        sports:{
          sport1,
          sport2
        }
        contact:"9925008667"
      }
  */
    let navigate = useNavigate();
    let location = useLocation();
    let user = useContext(UserContext);
    let [data, setData] = useState([]);
    let [dbid, setDbid] = useState({});
    let [teamM, setTeamM] = useState([]);
    useEffect(() => {

      
      function addData({rollN,sport}){
        setData(data.map(stud =>{
          if(stud.rollNo===rollN){
            return {
              ...stud,
              sports:[
                ...sports,
                {sport}
              ]
            };
          }
          else{
           return stud;
          }
        })   
        )
      }
      function createData(rollNo,name,contact,sport){
        setData([
          ...data,
          {
            name:{name},
            rollNo:{rollNo},
            sports:[
              sport
            ],
            contact:{contact}
          }
        ])
      }


      

        if (user) {
          
            get(
                ref(
                    database,
                    "users/" + user.uid + "/teams" 
                )
            ).then((snapshot) => {
              
                if (snapshot.exists()) {
                    // console.log(snapshot.val())
                    setDbid(snapshot.val());
                    
                    Object.entries(snapshot.val()).map(([key,value])=>{
                      // console.log(key+" "+value)
                      get(
                        ref(
                            database,
                            "sports/" + key + "/" + value
                        )
                    ).then((snapshot2)=>{
                     
                      if(snapshot2.exists()){
                        // console.log(snapshot2.val())
                        setTeamM(snapshot2.val().teamMembers);
                        
                        snapshot2.val().teamMembers.map(player=>{
                          if(data.find(a => a.key.rollNo===player.rollNo)){
                            addData(player.rollNo,key)
                          }
                          else{
                            createData(player.rollNo,player.name,player.contact,key)
                          }
                        })
                      }
                    })
                    })
                } else {
                    navigate("/dashboard");
                }
            });
        }
        console.log(data)
        
    }, [user, navigate,data]);

    const roleData = [];
    roleData[0] = {
        role: "Captain",
        name: data?.cpName,
        mobile: data?.cpPhone,
        email: data?.cpEmail,
        key: 1,
    };
    roleData[1] = {
        role: "Vice-Captain",
        name: data?.vcpName,
        mobile: data?.vcpPhone,
        email: data?.vcpEmail,
        key: 2,
    };

    const roleColumns = [
        {
            title: "Role",
            dataIndex: "role",
            key: "role",
            width: "10vw",
        },
        {
            title: "Name",
            dataIndex: "name",
            key: "name",
            width: "30vw",
        },
        {
            title: "Contact Number",
            dataIndex: "mobile",
            key: "mobile",
            width: "20vw",
        },
        {
            title: "Email",
            dataIndex: "email",
            key: "email",
            width: "20vw",
        },
    ];
    const teamColumns = [
        {
            title: "Name",
            dataIndex: "name",
            key: "name",
            width: "40vw",
        },
        {
            title: "Contact Number",
            dataIndex: "mobile",
            key: "mobile",
            width: "40vw",
        },
        {
          title: "Roll number",
          dataIndex: "rollNo",
          key: "rollNo",
          width: "40vw",
      },
      {
        title: "Sports",
        dataIndex: "sports",
        key: "rollNo",
        width: "40vw",
    }
    ];
   
    

    return (
      <>
        <div className="text-center bottom-0 sticky p-[2rem]  w-full -mb-5 bg-white flex flex-col items-center justify-center gap-6">
          <div className="flex flex-row justify-between">
            <h3 className="text-2xl">
             Contingency
            </h3>
          </div>
          {/* {data && (
            <>
              
              <Table
                columns={teamColumns}
                dataSource={data?.}
                bordered
                pagination={false}
              />
            </>
          )} */}
          <div className="ml-auto">
            
            {/* <Button
              type="default"
              onClick={() => {
                (sports[data?.sport]?navigate("/dashboard/edit", {
                  state: { data: data },
                }):
                navigate("/dashboard/editEmp", {
                  state: { data: data },
                }));
              }}
            >
              Edit Team
            </Button>
            {data && (
              <PDFDownloadLink
                document={<DownloadPDF data={data} user={user} />}
                fileName={data?.sport + ".pdf"}
              >
                {({ blob, url, loading, error }) =>
                  loading ? (
                    "Loading document..."
                  ) : (
                    <Button
                      type="primary"
                      className="bg-[#407cff] w-32 ml-5 scale-110 "
                    >
                      Download PDF
                    </Button>
                  )
                }
              </PDFDownloadLink>
            )} */}
          </div>
        </div>
      </>
    );
}