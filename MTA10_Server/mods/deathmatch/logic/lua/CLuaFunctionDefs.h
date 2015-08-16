/*****************************************************************************
*
*  PROJECT:     Multi Theft Auto v1.0
*  LICENSE:     See LICENSE in the top level directory
*  FILE:        mods/deathmatch/logic/lua/CLuaFunctionDefs.h
*  PURPOSE:     Lua function definitions class
*  DEVELOPERS:  Kent Simon <>
*               Christian Myhre Lundheim <>
*               Cecill Etheredge <>
*               Ed Lyons <>
*               Oliver Brown <>
*               Jax <>
*               Chris McArthur <>
*               Kevin Whiteside <>
*               lil_Toady <>
*               Alberto Alonso <rydencillo@gmail.com>
*
*  Multi Theft Auto is available from http://www.multitheftauto.com/
*
*****************************************************************************/

class CLuaFunctionDefs;
class CBlipManager;
class CMarkerManager;
class CPickupManager;
class CRadarAreaManager;
class CRegisteredCommands;
class CAccountManager;
class CColManager;
class CAccessControlListManager;

#ifndef __CLUAFUNCTIONDEFINITIONS_H
#define __CLUAFUNCTIONDEFINITIONS_H

#include "LuaCommon.h"
#include "CLuaMain.h"
#include "CLuaTimerManager.h"

#define LUA_ERROR() lua_pushboolean ( luaVM, false ); return 0;
#define LUA_DECLARE(x) static int x ( lua_State * luaVM );

extern CTimeUsMarker < 20 > markerLatentEvent;  // For timing triggerLatentClientEvent

class CLuaFunctionDefs
{
public:
    static void     Initialize ( class CLuaManager* pLuaManager, class CGame* pClientGame );

    static void DbFreeCallback ( CDbJobData* pJobData, void* pContext );
    static void DbExecCallback ( CDbJobData* pJobData, void* pContext );

    LUA_DECLARE ( DisabledFunction );
    LUA_DECLARE ( CallRemote );
    LUA_DECLARE ( FetchRemote );

    // Event functions
    LUA_DECLARE ( AddEvent );
    LUA_DECLARE ( AddEventHandler );
    LUA_DECLARE ( RemoveEventHandler );
    LUA_DECLARE ( GetEventHandlers );
    LUA_DECLARE ( TriggerEvent );
    LUA_DECLARE ( TriggerClientEvent );
    LUA_DECLARE ( CancelEvent );
    LUA_DECLARE ( GetCancelReason );
    LUA_DECLARE ( WasEventCancelled );
    LUA_DECLARE ( TriggerLatentClientEvent );
    LUA_DECLARE ( GetLatentEventHandles );
    LUA_DECLARE ( GetLatentEventStatus );
    LUA_DECLARE ( CancelLatentEvent );
    LUA_DECLARE ( AddDebugHook );
    LUA_DECLARE ( RemoveDebugHook );

    // Ped get functions
    LUA_DECLARE ( CreatePed );
    LUA_DECLARE ( GetPedArmor );
    LUA_DECLARE ( GetPedRotation );
    LUA_DECLARE ( IsPedChoking );
    LUA_DECLARE ( IsPedDead );
    LUA_DECLARE ( IsPedDucked );
    LUA_DECLARE ( GetPedStat );
    LUA_DECLARE ( GetPedTarget );
    LUA_DECLARE ( GetPedWeapon );
    LUA_DECLARE ( GetPedClothes );
    LUA_DECLARE ( DoesPedHaveJetPack );
    LUA_DECLARE ( IsPedOnGround );
    LUA_DECLARE ( GetPedFightingStyle );
    LUA_DECLARE ( GetPedMoveAnim );
    LUA_DECLARE ( GetPedGravity );
    LUA_DECLARE ( GetPedContactElement );
    LUA_DECLARE ( GetPedWeaponSlot );
    LUA_DECLARE ( IsPedDoingGangDriveby );
    LUA_DECLARE ( IsPedOnFire );
    LUA_DECLARE ( IsPedHeadless );
    LUA_DECLARE ( IsPedFrozen );
    LUA_DECLARE ( GetPedOccupiedVehicle );
    LUA_DECLARE ( GetPedOccupiedVehicleSeat );
    LUA_DECLARE ( IsPedInVehicle );
    LUA_DECLARE ( GetWeaponProperty );
    LUA_DECLARE ( GetOriginalWeaponProperty );
    LUA_DECLARE ( GetPedAmmoInClip );
    LUA_DECLARE ( GetPedTotalAmmo );

    // Ped set functions
    LUA_DECLARE ( SetPedArmor );
    LUA_DECLARE ( KillPed );
    LUA_DECLARE ( SetPedRotation );
    LUA_DECLARE ( SetPedStat );
    LUA_DECLARE ( AddPedClothes );
    LUA_DECLARE ( RemovePedClothes );
    LUA_DECLARE ( GivePedJetPack );
    LUA_DECLARE ( RemovePedJetPack );
    LUA_DECLARE ( SetPedFightingStyle );
    LUA_DECLARE ( SetPedMoveAnim );
    LUA_DECLARE ( SetPedGravity );
    LUA_DECLARE ( SetPedChoking );
    LUA_DECLARE ( WarpPedIntoVehicle );
    LUA_DECLARE ( RemovePedFromVehicle );
    LUA_DECLARE ( SetPedDoingGangDriveby );
    LUA_DECLARE ( SetPedAnimation );
    LUA_DECLARE ( SetPedAnimationProgress );
    LUA_DECLARE ( SetPedWeaponSlot );
    LUA_DECLARE ( SetPedOnFire );
    LUA_DECLARE ( SetPedHeadless );
    LUA_DECLARE ( SetPedFrozen );
    LUA_DECLARE ( reloadPedWeapon );
    LUA_DECLARE ( SetWeaponProperty );

    // Weapon give/take functions
    LUA_DECLARE ( GiveWeapon );
    LUA_DECLARE ( TakeWeapon );
    LUA_DECLARE ( TakeAllWeapons );
    LUA_DECLARE ( SetWeaponAmmo );
    LUA_DECLARE ( GetSlotFromWeapon );

    // Blip create/destroy functions
    LUA_DECLARE ( CreateBlip );
    LUA_DECLARE ( CreateBlipAttachedTo );

    // Blip get functions
    LUA_DECLARE ( GetBlipIcon );
    LUA_DECLARE ( GetBlipSize );
    LUA_DECLARE ( GetBlipColor );
    LUA_DECLARE ( GetBlipOrdering );
    LUA_DECLARE ( GetBlipVisibleDistance );

    // Blip set functions
    LUA_DECLARE ( SetBlipIcon );
    LUA_DECLARE ( SetBlipSize );
    LUA_DECLARE ( SetBlipColor );
    LUA_DECLARE ( SetBlipOrdering );
    LUA_DECLARE ( SetBlipVisibleDistance );

    // Object create/destroy functions
    LUA_DECLARE ( CreateObject );

    // Object get functions
    LUA_DECLARE ( GetObjectName );
    LUA_DECLARE ( GetObjectRotation );
    LUA_DECLARE ( GetObjectScale );

    // Object set functions
    LUA_DECLARE ( SetObjectName );
    LUA_DECLARE ( SetObjectRotation );
    LUA_DECLARE ( SetObjectScale );
    LUA_DECLARE ( MoveObject );
    LUA_DECLARE ( StopObject );

    // Radar area create/destroy funcs
    LUA_DECLARE ( CreateRadarArea );

    // Radar area get funcs
    LUA_DECLARE ( GetRadarAreaSize );
    LUA_DECLARE ( GetRadarAreaColor );
    LUA_DECLARE ( IsRadarAreaFlashing );
    LUA_DECLARE ( IsInsideRadarArea );

    // Radar area set funcs
    LUA_DECLARE ( SetRadarAreaSize );
    LUA_DECLARE ( SetRadarAreaColor );
    LUA_DECLARE ( SetRadarAreaFlashing );

    // Explosion funcs
    LUA_DECLARE ( CreateExplosion );

    // Fire funcs
    LUA_DECLARE ( CreateFire );

    // Ped body funcs?
    LUA_DECLARE ( GetBodyPartName );
    LUA_DECLARE ( GetClothesByTypeIndex );
    LUA_DECLARE ( GetTypeIndexFromClothes );
    LUA_DECLARE ( GetClothesTypeName );

    // Shape create funcs
    LUA_DECLARE ( CreateColCircle );
    LUA_DECLARE ( CreateColCuboid );
    LUA_DECLARE ( CreateColSphere );
    LUA_DECLARE ( CreateColRectangle );
    LUA_DECLARE ( CreateColPolygon );
    LUA_DECLARE ( CreateColTube );

    // Team get funcs
    LUA_DECLARE ( CreateTeam );
    LUA_DECLARE ( GetTeamFromName );
    LUA_DECLARE ( GetTeamName );
    LUA_DECLARE ( GetTeamColor );
    LUA_DECLARE ( GetTeamFriendlyFire );
    LUA_DECLARE ( GetPlayersInTeam );
    LUA_DECLARE ( CountPlayersInTeam );

    // Team set funcs
    LUA_DECLARE ( SetPlayerTeam );
    LUA_DECLARE ( SetTeamName );
    LUA_DECLARE ( SetTeamColor );
    LUA_DECLARE ( SetTeamFriendlyFire );

    // Water funcs
    LUA_DECLARE ( CreateWater );
    LUA_DECLARE ( SetWaterLevel );
    LUA_DECLARE ( ResetWaterLevel );
    LUA_DECLARE ( GetWaterVertexPosition );
    LUA_DECLARE ( SetWaterVertexPosition );
    LUA_DECLARE ( GetWaterColor );
    LUA_DECLARE ( SetWaterColor );
    LUA_DECLARE ( ResetWaterColor );

    // Weapon funcs
    LUA_DECLARE ( CreateWeapon );
    LUA_DECLARE ( GetWeaponNameFromID );
    LUA_DECLARE ( GetWeaponIDFromName );
    LUA_DECLARE ( FireWeapon );
    LUA_DECLARE ( SetWeaponState );
    LUA_DECLARE ( GetWeaponState );
    LUA_DECLARE ( SetWeaponTarget );
    LUA_DECLARE ( GetWeaponTarget );
    LUA_DECLARE ( SetWeaponOwner );
    LUA_DECLARE ( GetWeaponOwner );
    LUA_DECLARE ( SetWeaponFlags );
    LUA_DECLARE ( GetWeaponFlags );
    LUA_DECLARE ( SetWeaponFiringRate );
    LUA_DECLARE ( GetWeaponFiringRate );
    LUA_DECLARE ( ResetWeaponFiringRate );
    LUA_DECLARE ( GetWeaponAmmo );
    LUA_DECLARE ( GetWeaponClipAmmo );
    LUA_DECLARE ( SetWeaponClipAmmo );

    // Console functions
    LUA_DECLARE ( AddCommandHandler );
    LUA_DECLARE ( RemoveCommandHandler );
    LUA_DECLARE ( ExecuteCommandHandler );

    // JSON functions
    LUA_DECLARE ( toJSON );
    LUA_DECLARE ( fromJSON );

    // Standard server functions
    LUA_DECLARE ( GetMaxPlayers );
    LUA_DECLARE ( SetMaxPlayers );
    LUA_DECLARE ( OutputChatBox );
    LUA_DECLARE ( OutputConsole );
    LUA_DECLARE ( OutputDebugString );
    LUA_DECLARE ( OutputServerLog );
    LUA_DECLARE ( GetServerName );
    LUA_DECLARE ( GetServerHttpPort );
    LUA_DECLARE ( GetServerIP );
    LUA_DECLARE ( GetServerPassword );
    LUA_DECLARE ( SetServerPassword );
    LUA_DECLARE ( GetServerConfigSetting );
    LUA_DECLARE ( SetServerConfigSetting );

    LUA_DECLARE ( shutdown );

    // Utility vector math functions
    LUA_DECLARE ( GetDistanceBetweenPoints2D );
    LUA_DECLARE ( GetDistanceBetweenPoints3D );
    LUA_DECLARE ( GetEasingValue );
    LUA_DECLARE ( InterpolateBetween );

    // Util functions to make scripting easier for the end user
    // Some of these are based on standard mIRC script funcs as a lot of people will be used to them
    LUA_DECLARE ( GetTickCount_ );
    LUA_DECLARE ( GetCTime );
    LUA_DECLARE ( Split );
    LUA_DECLARE ( GetTok );
    LUA_DECLARE ( SetTimer );
    LUA_DECLARE ( KillTimer );
    LUA_DECLARE ( ResetTimer );
    LUA_DECLARE ( GetTimers );
    LUA_DECLARE ( IsTimer );
    LUA_DECLARE ( GetTimerDetails );
    LUA_DECLARE ( GetColorFromString );
    LUA_DECLARE ( Reference );
    LUA_DECLARE ( Dereference );
    LUA_DECLARE ( UtfLen );
    LUA_DECLARE ( UtfSeek );
    LUA_DECLARE ( UtfSub );
    LUA_DECLARE ( UtfChar );
    LUA_DECLARE ( UtfCode );
    LUA_DECLARE ( GetValidPedModels );

    // PCRE functions
    LUA_DECLARE ( PregFind );
    LUA_DECLARE ( PregReplace );
    LUA_DECLARE ( PregMatch );

    // Loaded Map Functions
    LUA_DECLARE ( GetRootElement );
    LUA_DECLARE ( LoadMapData );
    LUA_DECLARE ( SaveMapData );

    // Mesh Functions
    LUA_DECLARE ( CreateMesh );

    // All-Seeing Eye Functions
    LUA_DECLARE ( GetGameType );
    LUA_DECLARE ( GetMapName );
    LUA_DECLARE ( SetGameType );
    LUA_DECLARE ( SetMapName );
    LUA_DECLARE ( GetRuleValue );
    LUA_DECLARE ( SetRuleValue );
    LUA_DECLARE ( RemoveRuleValue );

    // Database funcs
    static void     DbQueryCallback ( CDbJobData* pJobData, void* pContext );
    LUA_DECLARE ( DbConnect );
    LUA_DECLARE ( DbExec );
    LUA_DECLARE ( DbQuery );
    LUA_DECLARE ( DbFree );
    LUA_DECLARE ( DbPoll );

    // Registry funcs
    LUA_DECLARE ( ExecuteSQLCreateTable );
    LUA_DECLARE ( ExecuteSQLDropTable );
    LUA_DECLARE ( ExecuteSQLDelete );
    LUA_DECLARE ( ExecuteSQLInsert );
    LUA_DECLARE ( ExecuteSQLSelect );
    LUA_DECLARE ( ExecuteSQLUpdate );
    LUA_DECLARE ( ExecuteSQLQuery );
    LUA_DECLARE ( GetPerformanceStats );

    // Account get funcs
    LUA_DECLARE ( GetAccount );
    LUA_DECLARE ( GetAccounts );
    LUA_DECLARE ( GetAccountName );
    LUA_DECLARE ( GetAccountPlayer );
    LUA_DECLARE ( IsGuestAccount );
    LUA_DECLARE ( GetAccountData );
    LUA_DECLARE ( GetAllAccountData );
    LUA_DECLARE ( GetAccountSerial );
    LUA_DECLARE ( GetAccountsBySerial );

    // Account set funcs
    LUA_DECLARE ( AddAccount );
    LUA_DECLARE ( RemoveAccount );
    LUA_DECLARE ( SetAccountPassword );
    LUA_DECLARE ( SetAccountData );
    LUA_DECLARE ( CopyAccountData );

    // Log in/out
    LUA_DECLARE ( LogIn );
    LUA_DECLARE ( LogOut );

    // Admin funcs
    LUA_DECLARE ( AddBan );
    LUA_DECLARE ( RemoveBan );

    LUA_DECLARE ( GetBans );
    LUA_DECLARE ( ReloadBanList );

    LUA_DECLARE ( GetBanIP );
    LUA_DECLARE ( GetBanSerial );
    LUA_DECLARE ( GetBanUsername );
    LUA_DECLARE ( GetBanNick );
    LUA_DECLARE ( GetBanTime );
    LUA_DECLARE ( GetUnbanTime );
    LUA_DECLARE ( GetBanReason );
    LUA_DECLARE ( GetBanAdmin );

    LUA_DECLARE ( SetUnbanTime );
    LUA_DECLARE ( SetBanReason );
    LUA_DECLARE ( SetBanAdmin );
    LUA_DECLARE ( SetBanNick );
    LUA_DECLARE ( IsBan );

    // Misc funcs
    LUA_DECLARE ( ResetMapInfo );
    LUA_DECLARE ( GetServerPort );

    // Settings registry funcs
    LUA_DECLARE ( Get );
    LUA_DECLARE ( Set );

    // Utility
    LUA_DECLARE ( Md5 );
    LUA_DECLARE ( Sha256 );
    LUA_DECLARE ( Hash );
    LUA_DECLARE ( TeaEncode );
    LUA_DECLARE ( TeaDecode );
    LUA_DECLARE ( Base64encode );
    LUA_DECLARE ( Base64decode );
    LUA_DECLARE ( GetNetworkUsageData );
    LUA_DECLARE ( GetNetworkStats );
    LUA_DECLARE ( GetVersion );
    LUA_DECLARE ( GetModules );
    LUA_DECLARE ( GetModuleInfo );
    LUA_DECLARE ( IsOOPEnabled );

private:
    // Static references to objects
    static CBlipManager*                                m_pBlipManager;
    static CLuaManager*                                 m_pLuaManager;
    static CMarkerManager*                              m_pMarkerManager;
    static CObjectManager*                              m_pObjectManager;
    static CPickupManager*                              m_pPickupManager;
    static CPlayerManager*                              m_pPlayerManager;
    static CRadarAreaManager*                           m_pRadarAreaManager;
    static CRegisteredCommands*                         m_pRegisteredCommands;
    static CElement*                                    m_pRootElement;
    static CScriptDebugging*                            m_pScriptDebugging;
    static CVehicleManager*                             m_pVehicleManager;
    static CTeamManager*                                m_pTeamManager;
    static CAccountManager*                             m_pAccountManager;
    static CColManager*                                 m_pColManager;
    static CResourceManager*                            m_pResourceManager;
    static CAccessControlListManager*                   m_pACLManager;
    static CLuaModuleManager*                           m_pLuaModuleManager;
};

#endif
